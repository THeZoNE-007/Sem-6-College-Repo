# Step-by-Step Hands-On Web Exploitation Tutorial

## **Part 1: Setting Up Your Environment**

### **1. Get Kali Linux**

- Download from [https://www.kali.org/get-kali/](https://www.kali.org/get-kali/)
- Run in a virtual machine using VirtualBox or VMware.

### **2. Install Necessary Tools**

Run the following in Kali's terminal:

```bash
sudo apt update && sudo apt install gobuster sqlmap nikto xsstrike
```

---

## **Part 2: robots.txt Exploitation**

### **Objective:** Find hidden directories

### **Commands:**

#### **1. On a Live Website**

- **Target:** [Google Gruyere](https://google-gruyere.appspot.com)
- Run:
  ```bash
  curl -s https://google-gruyere.appspot.com/robots.txt
  ```
- Look for disallowed directories like `/admin/` or `/backup/`.
- Try accessing them: `https://google-gruyere.appspot.com/admin/`

#### **2. Using an Automated Scanner**

```bash
nikto -h https://google-gruyere.appspot.com
```

---

## **Part 3: .htaccess File Exposure**

### **Objective:** Find hidden files

### **Commands:**

#### **1. On a Live Website**

- **Target:** [PortSwigger Web Security Academy](https://portswigger.net/web-security)
- Run:
  ```bash
  gobuster dir -u https://portswigger.net/web-security -w /usr/share/wordlists/dirb/common.txt -x txt,php,html
  ```
- If `.htaccess` is found, access it:
  ```bash
  wget https://portswigger.net/web-security/.htaccess
  cat .htaccess
  ```

---

## **Part 4: Cross-Site Scripting (XSS)**

### **Objective:** Inject JavaScript payloads

### **Commands:**

#### **1. Manual Injection**

- **Target:** [XSS Game by Google](https://xss-game.appspot.com/)
- Enter in input fields:
  ```html
  <script>alert('XSS')</script>
  ```
- Run in terminal:
  ```bash
  curl -X GET "https://xss-game.appspot.com/level1?param=<script>alert('XSS')</script>"
  ```

#### **2. Automated Scanning**

```bash
python3 xsstrike.py -u https://xss-game.appspot.com/level1
```

---

## **Part 5: Buffer Overflow Exploitation**

### **Objective:** Crash a program and inject shellcode

### **Practice On:** [Exploit Education - Protostar](https://exploit.education/protostar/)

#### **1. SSH into the Target**

```bash
ssh student@protostar.exploit.education
```

#### **2. Test Buffer Overflow**

```bash
python3 -c "print('A' * 100)" | ./vulnerable_binary
```

#### **3. Debug with GDB**

```bash
gdb ./vulnerable_binary
break main
run $(python3 -c "print('A' * 100")
info registers
```

---

## **Next Steps**

Would you like more advanced tutorials on **Burp Suite, SQL Injection, or privilege escalation?** Let me know! 😊


