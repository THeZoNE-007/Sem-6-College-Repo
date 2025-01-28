#!/bin/bash
fetchip() {

	ip addr show | grep "inet" | grep -v "127.0.0.1" | awk '(print $2)' | cut -d'/' -f1
	
}
 #scan all ports
 
scan_open_ports() {
	
	local ip == $1
	echo "scanning open ports in $ip.."
	nmap -p $ip | grep "open" | awk '[print $1]' | sed 's/[^0-9]//g'
 
}
