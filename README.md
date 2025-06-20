# ARP Traffic Inspector

## Objective
A Linux kernel module to detect and count ARP request/reply packets using Netfilter hooks.

## Setup Instructions

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
make
sudo insmod arp_traffic_inspector.ko

