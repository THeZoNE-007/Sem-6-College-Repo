Folders marked with **(RP)** are materials from **Dr. Rourab Paul**.  
Website link: [https://rourab.com/leclist.php?sub=PTW&year=2024-2025&sec=24](https://rourab.com/leclist.php?sub=PTW&year=2024-2025&sec=24)

Everything else unmarked is from **Dr. Bharat Jyoti Ranjan Sahoo**.

---
---

# INDEX — PTW GitHub Folder

## [2025-01-22 -- intro\_ptw](#)
1. Purpose of Pentest
2. Stages of Pentest - 1,2,3,&4
3. Vulnerability Assessment VS Pen Test
4. Types of Pentest - Black, White, & Gray Box
5. Benefits of Pentest

## [2025-01-22 -- script](#)
1. Why Scripting?
2. Popular options for Scripting
3. Purpose of Pentest
4. Stages of Pentest - 1,2,3,&4
5. Types of Pentest - Black, White, & Gray Box
6. Benefits of Pentest
7. Tutorials on:
    > Bash scripting
    > Python scripting
    -> C programs

## [2025-01-24 -- linux\_command](#)
1. Linux cmd line
2. Linux file system
3. Man pages
4. User privileges
    -> Add a user
    -> adding user to Sudoers file
    -> Switch users, use sudo
    -> create new file / directory
    -> copy, move, remove files
    -> add text to a file
    -> appending text to a file
5. File permissions
6. Editing files:
    -> Searching for text
    -> Editing a file with vi
 7. Data manipulation  
    -> using grep
    -> using sed
    -> pattern marking with awk
 8. Managing installed packages
9. Processes and Services
10. Managing Networking
    -> Setting static IP address
    -> Viewing network connections
11. Netcat: Swiss Army knife  of TCP/IP Connections
    -> Check to see port listening
    -> Opening cmd shell listener
    -> pushing cmd shell back to listener
12. Automating tasks with cron Jobs

## [2025-01-27 — metasploit](#)
1. Introduction
2. Key features
3. Components
4. Type of payloads
5. Workflow

## [2025-01-27 — MS08-067](#)
1. ms08-067
2. Details:
   -> Discovered
   -> CVE Identifier
   -> Vuln type
   -> Cause of Vuln
   -> Patch info
3. Steps 1,2,3,4,5,6,&7 - Demonstration of Attack
4. Type of Shell - Bind & Reverse

## [2025-01-20 — linux\_command-1](#)
1. Linux cmd line
2. Linux file system
3. Man pages
4. User privileges
   -> Add a user
   -> adding user to Sudoers file
   -> Switch users, use sudo
   -> create new file / directory
   -> copy, move, remove files
   -> add text to a file
   -> appending text to a file
5. File permissions
6. Editing files
Searching for text
Editing a file with vi
7. Data manipulation
   -> using grep
   -> using sed
   -> pattern marking with awk
8. Managing installed packages
9. Processes and Services
10. Managing Networking:
   -> Setting static IP address
   -> Viewing network connections
11. Netcat: Swiss Army knife  of TCP/IP Connections
   -> Check to see port listening
   -> Opening cmd shell listener
   -> pushing cmd shell back to listener
12. Automating tasks with cron Jobs

## [2025-01-31 — dns](#)
-> Entire flow of “How DNS works?”

## [2025-01-31 — smb\_netbios](#)
1. workspace
2. hosts & services commands
3. SMB & NetBIOS

## [2025-02-03 — modules\_metasploit](#)
1. show cmd
2. auxiliary modules:
   -> scanner
   -> admin
   -> dos
   -> fuzzers
   -> gather
   -> spoof
3. Common auxiliary modules
   -> open port scan
   -> enumerating SMB shares
   -> Brute-forcing SMB Login
   -> SMB vuln scan
   -> SYN Flood atk
   -> Apache DOS (Range Header atk)
   -> SMBLoris atk (Win SMB Dos)
   -> Types of DoS
4. SYN FLood (DoS)
5. Apache Web Server via Memory exhaustion (DoS)
6. Windows SMB Resource Exhaustion
7. ARP Spoofing

## [2025-02-07 — msf\_arp\_spoof](#)
1. Steps of ARP Poisoning
2. ARP Spoof recovery
3. why arp spoof possible

## [2025-02-24 — info\_gathering](#)
1. OSINT gathering
   -> netcraft
   -> whois lookups
   -> DNS Reconnaissance
       -> Nslookup
       -> Host
       -> Zone Transfers
   -> Searchig Email Address
     
## [2025-03-04 — web application scanning](#)
1. robots.txt
2. .htaccess
3. cross-site sripting (XSS) exploit — buffer overflow
4. An example C lang. code for Buffer Overflow atk
5. Exploiting Buffer Overflow
   -> Fuzzing i/p
   -> Finding offset using gdb
   -> example python code

## [2025-03-05 — maltego](#)
1. Introduction
2. Why maltego
3. getting started maltego
4. Person Entity
5. Domain Entity

## [2025-03-06 — Buffer Overflow & SQL injection](#)
1. What is BO?  
   -> Stack vs Heap OF
   -> Practical Exercises
   -> Real-World Exploitation Scenarios
2. SQL Injection (SQLi)  
   -> Types of SQL Injection
   -> How to Identify SQL Injection
   -> Exploiting SQL Injection
   -> Writing an SQL Injection Exploit (Python)
   -> How to Prevent SQL Injection
   -> Steps to Set Up the SQL Injection Lab
   -> Performing SQL Injection
   -> Fixing the Vulnerability
3. APPENDIX 1 - writing proper kali & msf cmds

## [2025-03-07 — nmap](#)
1. Port scanning
   -> manual port scan
   -> nmap port scan
       -> syn scan
       -> version scan
       -> udp scan
       -> scanning specific port

## [2025-03-10 — tcpdump (includes Wireshark)](#)
1. Intro
2. What is tcpdump?
3. Basic syntax
4. tcpdump options
5. filters
6. example scenarios
7. Analyzing traffic for pentest
8. Saving & Analyzing Captured Packets
9. Security considerations
10. Conclusion
11. Wireshark intro
12. WS Filters
13. WS Filter Examples
14. Tips to use WS Filters effectively
15. Conclusion

## [2025-03-10 — Assignment tcpdump](#)
-> Contains questions related to tcpdump and wireshark

## [2025-03-10 — nessus](#)
1. Installation
2. Configuration
3. Scanning
4. Analyzing report
5. Vulns in Apache Tomcat 9.0.0.M1 < 9.0.3.1
6. metasploit script on Tomcat
7. SMB Signing disabled then?

## [2025-03-12 -- web_app_exp](#)
1. Web Application Scanning
   -> Nikto
   -> Attacking XAMPP
   -> Default Credentials of XAMPP 1.7.3 and earlier ver
2. Manual Analysis
   -> Explore strange port
   -> Finding valid usernames
   -> Summary
3. Web Application Exploitation
4. Surveying the Webspace
5. Concept of Robots.txt
6. Concept of .htaccess / http.conf
7. Quick soln to XSS
8. Reducing BO
9. Avoiding SQLi
10. Armitage - GUI front-end for msf
11. OWASP ZAP - website vuln scanner
12. Search and Destroy with Burpsuite

## [2025-03-13 — DNS_Working](#)
1. ARP Cache Poisoning
   -> Steps to Perform ARP Cache Poisoning Using Arpspoof
2. How DNS Works?
   -> DNS Resolution Example
   -> DNS Resolution Process
   -> DNS Cache Poisoning Attack
   -> Setting Up DNS Spoofing in Kali
   -> Demonstrating the Attack
   -> DNS SUMMARY
3. SSL Attacks Overview
   -> SSL Basics
   -> SSL Man in the Middle
   -> SSL Man-in-the-Middle Attack
   -> SSL Stripping Attack
   -> Defending Against SSL Attacks
4. Assignment

## [2025-03-25 — Ch 08 - Pentesting_Exploitation](#)
1. XAMPP Installation on Window XP
2. Exploiting MS08-067 with msf
3. Uploading Files Using WebDAV
4. Uploading a PHP Reverse Shell
5. Exploiting Open phpMyAdmin
6. Exercise questions
7. Downloading a File with TFTP
   -> Overview
   -> Steps
   -> Troubleshooting Steps
8. Summary

## [2025-03-31 — Exploiting phpMyadmin](#)
1. Overview  
2. Exploitation steps

## [2025-04-01 — Ch 09 - Exploiting Password](#)
1. Exploiting password
2. Exploiting a Buffer Overflow in ThirdParty Software
3. Exploiting Third-Party Web Applications
4. Exploiting a Compromised Service

## [2025-04-03 — Password Attacks](#)
1. Password SAFETY
   -> Challenges
   -> Mitigation
   -> Common mistakes
2. Offline Password Attacks/ Find Hash
   -> Zervit 0.4
   -> SLMail 5.5
   -> 3Com TFTP 2.0.1 (Optional for today class)
   -> Testing port 3232/ Zervit
3. FINDING A SENSITIVE FILE boot.ini
4. Downloading the Windows SAM
5. Finding Valid Usernames to use the VRFY SMTP command


