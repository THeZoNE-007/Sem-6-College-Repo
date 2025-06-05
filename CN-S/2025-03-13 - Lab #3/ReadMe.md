Absolutely! Here's the final and fully corrected version of **Objective 2**, now including a **note on why the access list number is 10** (due to the valid range 1–99 for standard ACLs):

---

## **LAB Experiment 03**

### **Objective 2: Configuration and Verification of a Standard Access List for Permit and Deny to a Remote Server**

---

#### **Pre-requisites (Network Topology):**

* **x4 PCs**

  * PC1 IP: 200.100.100.2
  * PC2 IP: 200.100.100.3
  * PC3 IP: 200.100.100.4
  * PC4 IP: 200.100.100.5

* **x1 Switch (2960)**

  * All 4 PCs are connected to this switch.

* **x1 Router (Left Router)**

  * Switch connected to Router’s **Gig0/0**
  * Default Gateway: **200.100.100.1**

* **x1 Router (Right Router)**

  * Left Router’s **Gig0/1** connected to Right Router’s **Gig0/1**
  * IPs: **Left Gig0/1: 10.10.10.1**, **Right Gig0/1: 10.10.10.2**

* **x1 More Switch (2960)**

  * Right Router’s **Gig0/0** (IP: 210.100.100.1) connected to this switch

* **x1 Server**

  * Connected to the second switch
  * IP: **210.100.100.2**

> 🔁 *Routing between routers is assumed to be configured using either static routes or RIP.*

---

#### **Configuration Steps (Right Router - Applying Standard ACL):**

Navigate to the **CLI of the Right Router** and enter the following:

1. **`en`**

   * **Explanation**: Enters privileged EXEC mode.
   * **Purpose**: Enables command execution in higher privilege mode.

2. **`config t`**

   * **Explanation**: Enters global configuration mode.
   * **Purpose**: Prepares the router for configuration.

3. **`access-list 10 deny host 200.100.100.2`**

   * **Explanation**: Denies all packets from PC1.
   * **Purpose**: Blocks access to the server for this specific source IP.
   * **Note**: **Access-list number `10` is used because standard access lists must be numbered in the range `1–99`.**

4. **`access-list 10 permit any`**

   * **Explanation**: Permits traffic from all other hosts.
   * **Purpose**: Allows access for all clients except the denied one.

5. **`interface gig0/1`**

   * **Explanation**: Enters the interface facing the Left Router.
   * **Purpose**: This is where traffic from PCs enters before reaching the server.

6. **`ip access-group 10 in`**

   * **Explanation**: Applies ACL 10 in the inbound direction.
   * **Purpose**: Filters traffic as it enters toward the server.

7. **`exit`**

   * **Explanation**: Exits interface configuration mode.
   * **Purpose**: Returns to global configuration.

8. **`do write`**

   * **Explanation**: Saves configuration to NVRAM.
   * **Purpose**: Ensures configuration is retained after reboot.

---

#### **Verification Steps (PC to Server):**

Perform these tests **before and after** applying the ACL:

1. **From PC1 and PC2:**

   * **Command**: `ping 210.100.100.2`

     * **Before ACL**: Reply received from server.
     * **After ACL**: PC1 blocked; PC2 succeeds.

   * **Command**: `ftp 210.100.100.2`

     * **Before ACL**: FTP session successful.
     * **After ACL**: PC1 access denied; PC2 allowed.

   * **Web Access:**

     * **Navigate**: **Desktop → Web Browser**
     * **URL**: `http://210.100.100.2`
     * **Before ACL**: Web page loads on all PCs.
     * **After ACL**: PC1 denied; others succeed.

---

#### **Summary of Objective 2:**

* Configured **Standard ACL (No. 10)** on **Right Router’s `Gig0/1`** interface (inbound).
* Denied access to the server for **PC1 (200.100.100.2)** only.
* **Verified access control** using Ping, FTP, and HTTP tests.
* **Explained ACL numbering** (standard ACLs use numbers from 1 to 99).
* Confirmed that the ACL **successfully blocks only the specified host**.

---
---
Sure! Here's the **full combined Markdown content** for **Objective 2 and Objective 3** of **Lab Experiment 03** rendered directly here:

---

# **LAB Experiment 03**

## **Objective 2: Configuration and Verification of a Standard Access List for Permit and Deny to a Remote Server**

---

### **Pre-requisites (Network Topology):**

* **x4 PCs**

  * PC1 IP: 200.100.100.2
  * PC2 IP: 200.100.100.3
  * PC3 IP: 200.100.100.4
  * PC4 IP: 200.100.100.5

* **x1 Switch (2960)**

  * All 4 PCs are connected to this switch.

* **x1 Router (Left Router)**

  * Switch connected to Router’s **Gig0/0**
  * Default Gateway: **200.100.100.1**

* **x1 Router (Right Router)**

  * Left Router’s **Gig0/1** connected to Right Router’s **Gig0/1**
  * IPs: **Left Gig0/1: 10.10.10.1**, **Right Gig0/1: 10.10.10.2**

* **x1 More Switch (2960)**

  * Right Router’s **Gig0/0** (IP: 210.100.100.1) connected to this switch

* **x1 Server**

  * Connected to the second switch
  * IP: **210.100.100.2**

> 🔁 *Routing between routers is assumed to be configured using either static routes or RIP.*

---

### **Configuration Steps (Right Router - Applying Standard ACL):**

1. `en` – Enters privileged EXEC mode
2. `config t` – Enters global configuration mode
3. `access-list 10 deny host 200.100.100.2`

   * Denies all packets from PC1
   * **Note**: Access-list number `10` is used because standard ACLs must be numbered in the range `1–99`.
4. `access-list 10 permit any` – Allows all other IPs
5. `interface gig0/1` – Interface facing Left Router
6. `ip access-group 10 in` – Applies ACL 10 inbound
7. `exit`
8. `do write` – Saves the configuration

---

### **Verification:**

* **PC1**: `ping`, `ftp`, `http://210.100.100.2` → ❌ **Blocked**
* **PC2–PC4**: All services → ✅ **Allowed**

---

### **Summary:**

* Standard ACL applied on Right Router (`Gig0/1 in`)
* Denied: PC1
* Others allowed
* ACL 10 used (Standard range: 1–99)

---

## **Objective 3: Configuration and Verification of an Extended Access List for Permit and Deny to a Remote Server (HTTP / FTP / ICMP)**

---

### **Configuration Steps (Left Router - Applying Extended ACL):**

1. `en`
2. `config t`
3. `access-list 108 deny tcp host 200.100.100.2 host 210.100.100.2 eq www`

   * Denies HTTP (port 80) from PC1
   * `eq www` = `eq 80`
4. `access-list 108 deny tcp host 200.100.100.3 host 210.100.100.2 eq 21`

   * Denies FTP from PC2
5. `access-list 108 deny icmp host 200.100.100.4 host 210.100.100.2`

   * Denies ping from PC3
6. `access-list 108 permit ip any any`

   * Allows all else
   * First `any`: any source; second `any`: any destination
7. `interface gig0/0`
8. `ip access-group 108 in`
9. `exit`, `do write`

> 📌 **Access-list number `108` is used** because **extended ACLs use number range 100–199**, which allows filtering by protocol and port numbers.

---

### **Verification:**

* **PC1 (HTTP test via Web Browser)** → ❌ Blocked
* **PC2 (FTP test via Command Prompt)** → ❌ Blocked
* **PC3 (Ping via Command Prompt)** → ❌ Blocked
* **PC4** → ✅ All services allowed

---

### **Summary:**

* Extended ACL applied on Left Router (`Gig0/0 in`)
* Denied:

  * PC1: HTTP
  * PC2: FTP
  * PC3: Ping
* Allowed: All other traffic
* ACL 108 used (Extended ACL range: 100–199)
