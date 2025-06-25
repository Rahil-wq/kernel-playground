# ARP Traffic Inspector

This kernel module inspects ARP packets using Netfilter.

## Guide

ARP Traffic Inspector – Kernel Module

1. Prepare the Environment
Install necessary tools:

	sudo apt update
	sudo apt install build-essential linux-headers-$(uname -r)

2. Create the Module Files
a. Create the folder:

		mkdir arp_traffic_inspector
		cd arp_traffic_inspector

b. Create arp_traffic_inspector.c: 
	
3. Create the Makefile


4. Compile the Module

		Make

5. Insert the Module
Load the module into the kernel:

		sudo insmod arp_traffic_inspector.ko

Check kernel log:

	dmesg | tail

6. Generate ARP Traffic
Ping gateway

	ping -c 1 192.168.1.1

Then check kernel messages:

	dmesg | tail

7. Remove the Module
unload the module:

	sudo rmmod arp_traffic_inspector


GitHub Instructions

1-	Initialize Git:

	git init

2-	Stage and commit files:

	git add .
	git commit -m "Add ARP Traffic Inspector module"
 
3-	Connect to my forked GitHub repo:

	git branch -M main
	git remote add origin https://github.com/YOUR_USERNAME/kernel-playground.git

4-	Push to GitHub:

	git push -u origin master

  What to Expect

  ARP Traffic Inspector project will appear under projects/arp_traffic_inspector/ in your GitHub repository.
  You will see messages like "Received ARP packet" and "Sent ARP packet" in dmesg.
  This project uses Netfilter to hook into incoming and outgoing packets.

To see logs

	dmesg | tail -n 20





