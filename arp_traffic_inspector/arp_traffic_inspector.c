// this is the code for Salsan arp traffic inspector


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/netfilter.h>
#include <linux/netfilter_arp.h>
#include <linux/skbuff.h>
#include <linux/if_arp.h>

static struct nf_hook_ops nfho;

// Hook function to handle ARP packets
static unsigned int arp_hook_func(void *priv,
                                  struct sk_buff *skb,
                                  const struct nf_hook_state *state)
{
    pr_info("🚀 Received ARP packet\n");
    return NF_ACCEPT;
}

static int __init arp_module_init(void)
{
    nfho.hook = arp_hook_func;
    nfho.pf = NFPROTO_ARP;        // Protocol family ARP
    nfho.hooknum = NF_ARP_IN;     // ARP input hook
    nfho.priority = 0;            // Neutral priority

    nf_register_net_hook(&init_net, &nfho);

    pr_info("🧠 ARP Traffic Inspector loaded\n");
    return 0;
}

static void __exit arp_module_exit(void)
{
    nf_unregister_net_hook(&init_net, &nfho);
    pr_info("🧹 ARP Traffic Inspector unloaded\n");
}

module_init(arp_module_init);
module_exit(arp_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Netfilter module to detect ARP packets");

