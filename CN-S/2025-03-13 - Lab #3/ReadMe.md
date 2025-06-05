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
### **Objective 3: Configuration and Verification of an Extended Access List for Permit and Deny to a Remote Server (HTTP / FTP / ICMP)**

---

#### **Pre-requisites (Same Network Topology as Objective 2):**

* **x4 PCs**

  * PC1 IP: 200.100.100.2
  * PC2 IP: 200.100.100.3
  * PC3 IP: 200.100.100.4
  * PC4 IP: 200.100.100.5

* **x1 Switch (2960)** — connects all 4 PCs

* **x1 Left Router**

  * PC switch connected to **Gig0/0** (IP: 200.100.100.1)

* **x1 Right Router**

  * Left Router’s **Gig0/1** <--> Right Router’s **Gig0/1** (IPs: 10.10.10.1 ↔ 10.10.10.2)
  * Right Router’s **Gig0/0** connects to server-side switch (IP: 210.100.100.1)

* **x1 Server**

  * IP: 210.100.100.2, connected to switch on the right

> 🛠 *Routing (Static or RIP) is assumed to be pre-configured for connectivity.*

---

#### **Configuration Steps (Left Router - Applying Extended ACL):**

Enter the following commands on the **Left Router**:

1. **`en`**

   * **Explanation**: Enters privileged EXEC mode.
   * **Purpose**: Allows router configuration.

2. **`config t`**

   * **Explanation**: Enters global configuration mode.
   * **Purpose**: Prepares router for changes.

3. **`access-list 108 deny tcp host 200.100.100.2 host 210.100.100.2 eq www`**

   * **Explanation**: Denies HTTP traffic (TCP port 80) from **PC1** to the Server.
   * **Note**: `eq www` is equivalent to `eq 80`, which represents the HTTP service.

4. **`access-list 108 deny tcp host 200.100.100.3 host 210.100.100.2 eq 21`**

   * **Explanation**: Denies FTP traffic (TCP port 21) from **PC2** to the Server.
   * **Note**: FTP uses port 21 by default.

5. **`access-list 108 deny icmp host 200.100.100.4 host 210.100.100.2`**

   * **Explanation**: Denies ICMP traffic (ping) from **PC3** to the Server.
   * **Note**: Here, protocol is explicitly set to `icmp` instead of `tcp`.

6. **`access-list 108 permit ip any any`**

   * **Explanation**: Allows all other IP traffic not explicitly denied.
   * **Purpose**:

     * The **first `any`** means any source IP.
     * The **second `any`** means any destination IP.
     * **Why it's used**: Without this line, all remaining traffic would be implicitly denied (default behavior of ACLs).

7. **`interface gig0/0`**

   * **Explanation**: Enters the interface receiving traffic from the PC LAN.
   * **Purpose**: Correct interface to filter traffic before it’s routed.

8. **`ip access-group 108 in`**

   * **Explanation**: Applies ACL 108 in the inbound direction.
   * **Purpose**: Ensures filtering takes place as traffic enters from PCs.

9. **`exit`** and **`do write`**

   * **Explanation**: Exit configuration mode and save changes.
   * **Purpose**: Finalize and store ACL configuration.

> 📌 **Note**: Access-list number **`108`** is used because **extended access lists** must be numbered in the range **100 to 199**. Unlike standard ACLs (1–99), extended ACLs allow filtering based on **source IP, destination IP, protocol, and port number** — enabling precise control.

---

#### **Verification Steps (By Host and Service):**

Perform the following tests from each relevant PC:

---

##### ✅ **From PC1 (200.100.100.2)**

* **Tested Service**: HTTP
* **Method**:

  * Navigate to **Desktop → Web Browser**
  * Type `http://210.100.100.2`
* **Result**: ❌ **Unreachable**
* **Explanation**: Blocked by ACL rule denying HTTP (port 80) traffic from this host.
* **Other Services**: FTP and ping are accessible.

---

##### ✅ **From PC2 (200.100.100.3)**

* **Tested Service**: FTP
* **Method**:

  * Open **Command Prompt**
  * Run `ftp 210.100.100.2`
* **Result**: ❌ **Unreachable**
* **Explanation**: Blocked by ACL rule denying FTP (port 21) from this host.
* **Other Services**: HTTP and ping are accessible.

---

##### ✅ **From PC3 (200.100.100.4)**

* **Tested Service**: ICMP (Ping)
* **Method**:

  * Open **Command Prompt**
  * Run `ping 210.100.100.2`
* **Result**: ❌ **Unreachable**
* **Explanation**: Blocked by ACL rule denying ICMP traffic.
* **Other Services**: FTP and HTTP are accessible.

---

##### ✅ **From PC4 (200.100.100.5)**

* **Tested Services**: Ping, FTP, HTTP
* **Method**: Use all services as normal
* **Result**: ✅ **All Accessible**
* **Explanation**: This host is not matched by any deny rule, and falls under `permit ip any any`.

---

#### **Summary of Objective 3:**

* Configured an **Extended Access Control List (ACL 108)** on the **Left Router’s `Gig0/0`** interface (inbound).
* Access Denials:

  * **PC1**: Denied HTTP (port 80)
  * **PC2**: Denied FTP (port 21)
  * **PC3**: Denied ping (ICMP)
* All other traffic is explicitly allowed using `permit ip any any`.
* **Access-list number `108` was used** because **extended ACLs use the number range 100–199**, enabling protocol- and port-level filtering.
* Verified ACL functionality by testing specific service access per host.
