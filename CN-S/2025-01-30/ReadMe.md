# LAB Experiment 01

## **Objective 3: SSH Configuration (local login authentication with ssh)**

### **1. `username admin privilege 15 secret iter123`**
- **Explanation**: Creates a user named **admin** with full administrative privileges (privilege level 15) and sets a secure password **iter123** for login.
- **Purpose**: Allows full administrative access to the router with a secure password.

### **2. `username guest privilege 4 secret guest123`**
- **Explanation**: Creates a **guest** user with a lower privilege level (4) and sets the password to **guest123**.
- **Purpose**: Provides limited access to the router for the **guest** user.

### **3. `line con 0`**
- **Explanation**: Configures the **console line (con)**, which is used for local management through the router's console port.
- **Purpose**: Configures local access for managing the router via console.

### **4. `login local`**
- **Explanation**: Specifies that user authentication for the **console line** should use the **local username and password database**.
- **Purpose**: Ensures users are prompted for a username and password when accessing the router via the console.

### **5. `exit`**
- **Explanation**: Exits from the **line con** configuration mode and returns to global configuration mode.
- **Purpose**: Allows you to move back to global configuration after configuring console line settings.

### **6. `line vty 0 4`**
- **Explanation**: Configures the **VTY lines (Virtual Teletype)**, allowing remote access via Telnet or SSH. The **0 to 4** range allows up to five remote sessions.
- **Purpose**: Enables remote management through VTY lines.

### **7. `login local`**
- **Explanation**: Ensures that remote access via **VTY lines** uses the local username and password database for authentication.
- **Purpose**: Prompts remote users to log in with their credentials for accessing the router.

### **8. `transport input ssh`**
- **Explanation**: Configures the router to accept **SSH** connections only for remote access, disabling **Telnet**.
- **Purpose**: Ensures encrypted, secure access to the router via SSH, preventing Telnet (which is unencrypted).

### **9. `exit`**
- **Explanation**: Exits from the **line vty** configuration mode and returns to global configuration mode.
- **Purpose**: Allows you to return to global configuration after modifying remote access settings.

### **10. `hostname r1`**
- **Explanation**: Sets the router’s hostname to **r1**.
- **Purpose**: Changes the router's name, which will be displayed in the command prompt.

### **11. `ip domain-name cn.com`**
- **Explanation**: Configures the router's **domain name** to **cn.com**.
- **Purpose**: Required for generating **RSA keys** for **SSH**.

### **12. `crypto key generate rsa`**
- **Explanation**: Generates an **RSA key pair** required for **SSH** encryption.
- **Purpose**: Ensures secure communication through SSH by creating the necessary encryption keys.

### **13. Prompted to Enter Key Size: `How many bits in the modulus [512]`**
- **Explanation**: You are prompted to specify the number of bits for the **RSA key modulus**. Typically, **1024 bits** is used for better security.
- **Purpose**: More bits in the key modulus provide stronger encryption.

### **14. `ip ssh version 2`**
- **Explanation**: Configures the router to use **SSH version 2** for secure remote access.
- **Purpose**: Ensures SSH version 2 is used, providing stronger security than version 1.

### **15. `end`**
- **Explanation**: Exits global configuration mode and returns to **privileged EXEC mode**.
- **Purpose**: Ends the configuration session and returns to the normal operational mode.

### **16. `exit`**
- **Explanation**: Closes the current CLI session.
- **Purpose**: Ends the CLI session with the router.

---

## **Objective 2: Telnet Configuration (local login authentication without ssh)**

### **1. `no transport input ssh`**
- **Explanation**: Disables **SSH** as a transport method for remote access on the VTY lines.
- **Purpose**: Removes SSH, allowing Telnet to be configured as the remote access method.

### **2. `no ip ssh version 2`**
- **Explanation**: Disables **SSH version 2**.
- **Purpose**: Fully disables SSH and prepares the router for Telnet access.

### **3. `line vty 0 4`**
- **Explanation**: Configures the **VTY lines** (lines 0 to 4) for remote access.
- **Purpose**: Prepares the router to accept remote Telnet connections.

### **4. `transport input telnet`**
- **Explanation**: Enables **Telnet** as the transport method for remote access on the VTY lines.
- **Purpose**: Configures the router to accept **Telnet** connections from remote devices.

### **5. `exit`**
- **Explanation**: Exits from the **line vty** configuration mode.
- **Purpose**: Returns to global configuration mode after modifying the VTY lines for Telnet.

---

### **Remote Connection via Telnet**

#### **6. From PC: `ping 192.168.1.1`**
- **Explanation**: The **PC** sends a **ping** to the router at IP address **192.168.1.1** to verify network connectivity.
- **Purpose**: Ensures that the PC can reach the router and that the network path is functioning.

#### **7. From PC: `telnet 192.168.1.1`**
- **Explanation**: Initiates a **Telnet** connection to the router at **192.168.1.1**.
- **Purpose**: Attempts to establish a Telnet session to the router from the PC.

#### **8. Login as `admin` user:**
- **Explanation**: The **admin** user is prompted to enter the **username** and **password**.
  - Username: **admin**
  - Password: **iter123** (the previously configured admin password).
- **Purpose**: Provides **admin** level access to the router after login.

#### **9. From PC: `telnet 192.168.1.1` (again with guest credentials)**
- **Explanation**: Initiates another **Telnet** session, this time logging in as the **guest** user.
  - Username: **guest**
  - Password: **guest123** (the previously configured guest password).
- **Purpose**: Logs into the router using **guest** credentials.

#### **10. `enable` and entering the guest secret:**
- **Explanation**: The **guest** user enters **privileged EXEC mode** by typing **`enable`** and entering the **secret password** (`gm123`).
- **Purpose**: Grants **guest** user higher-level access (privileged mode) on the router.

---

## **Summary of SSH and Telnet Configuration:**

### **SSH Configuration:**
1. Created users (`admin` and `guest`) with specified privilege levels and passwords.
2. Configured **local authentication** for console and remote access.
3. Enabled **SSH** for encrypted remote access, disabling Telnet for security.
4. Set up RSA encryption keys and SSH version 2 for secure communication.
5. Secured remote access via SSH for the **admin** and **guest** users.

### **Telnet Configuration:**
1. Disallowed SSH and enabled **Telnet** for remote access.
2. Configured the router to accept **Telnet** connections on the **VTY lines**.
3. Verified network connectivity and successfully connected using Telnet with both **admin** and **guest** users.
4. Allowed the **guest** user to elevate privileges through the **`enable`** command using the secret password.

This configuration provides a secure setup with both **SSH** (for secure remote access) and **Telnet** (for remote management, albeit less secure), depending on the method chosen for connection.
