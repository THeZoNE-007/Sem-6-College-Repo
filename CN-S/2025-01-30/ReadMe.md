## **LAB Experiment 01**

### **Objective 3: SSH Configuration (local login authentication with ssh)**

#### **Configuration Steps (SSH)**:

1. **`username cnlab01 privilege 15 secret iter123`**
   - **Explanation**: Creates an **admin user** named **cnlab01** with full administrative privileges (privilege level 15) and sets a secure password **iter123** for login.
   - **Purpose**: Allows full administrative access to the router with a secure password.

2. **`username cnlabguest privilege 1 secret lab123`**
   - **Explanation**: Creates a **guest user** named **cnlabguest** with a lower privilege level (1) and sets the password to **lab123**.
   - **Purpose**: Provides limited access to the router for the **guest** user.

   #### **Note**: Privilege levels range from **0-15**, with 15 being the highest (admin), and 1 being the lowest (usually for guests). Levels **2-14** are customizable, typically for different access control needs.

3. **`line con 0`**
   - **Explanation**: Configures the **console line (con)**, used for local management through the router's console port.
   - **Purpose**: Configures local access for managing the router via console.

4. **`login local`**
   - **Explanation**: Specifies that **local username and password authentication** should be used for the **console line**.
   - **Purpose**: Ensures users are prompted for a username and password when accessing the router via the console.

5. **`exit`**
   - **Explanation**: Exits from the **line con** configuration mode and returns to global configuration mode.
   - **Purpose**: Allows you to return to global configuration after configuring console line settings.

6. **`line vty 0 4`**
   - **Explanation**: Configures **VTY lines (0-4)** for remote access (via Telnet or SSH).
   - **Purpose**: Enables remote management through VTY lines.

7. **`login local`**
   - **Explanation**: Ensures that remote access via **VTY lines** uses the local username and password database for authentication.
   - **Purpose**: Prompts remote users to log in with their credentials for accessing the router.

8. **`transport input ssh`**
   - **Explanation**: Configures the router to accept **SSH** connections only for remote access, disabling **Telnet**.
   - **Purpose**: Ensures encrypted, secure access to the router via SSH, preventing Telnet (which is unencrypted).

9. **`exit`**
   - **Explanation**: Exits from the **line vty** configuration mode and returns to global configuration mode.
   - **Purpose**: Allows you to return to global configuration after modifying remote access settings.

10. **`hostname r1`**
    - **Explanation**: Sets the router’s hostname to **r1**.
    - **Purpose**: Changes the router's name, which will be displayed in the command prompt.

11. **`ip domain-name cn.com`**
    - **Explanation**: Configures the router's **domain name** to **cn.com**.
    - **Purpose**: Required for generating **RSA keys** for **SSH**.

12. **`crypto key generate rsa`**
    - **Explanation**: Generates an **RSA key pair** required for **SSH** encryption.
    - **Purpose**: Ensures secure communication through SSH by creating the necessary encryption keys.

13. **Prompted to Enter Key Size: `How many bits in the modulus [512]`**
    - **Explanation**: You are prompted to specify the number of bits for the **RSA key modulus**. Typically, **1024 bits** is used for better security.
    - **Purpose**: More bits in the key modulus provide stronger encryption.

14. **`ip ssh version 2`**
    - **Explanation**: Configures the router to use **SSH version 2** for secure remote access.
    - **Purpose**: Ensures SSH version 2 is used, providing stronger security than version 1.

15. **`end`**
    - **Explanation**: Exits global configuration mode and returns to **privileged EXEC mode**.
    - **Purpose**: Ends the configuration session and returns to the normal operational mode.

16. **`exit`**
    - **Explanation**: Closes the current CLI session.
    - **Purpose**: Ends the CLI session with the router.

---

#### **Executing SSH from PC**:

1. **Verify Network Connectivity:**
   - **Command**: `ping 192.168.1.1`
   - **Explanation**: The **PC** sends a **ping** to the router at IP address **192.168.1.1** to verify network connectivity.
   - **Purpose**: Ensures that the PC can reach the router and the network is functioning.

2. **Initiate SSH Connection:**
   - **Command**: `ssh -l cnlab01 192.168.1.1`
   - **Explanation**: The **PC** attempts to establish an **SSH** session to the router with the **username** **cnlab01**.
   - **Purpose**: This will prompt for the **password** (`iter123`) to securely log into the router.

3. **Login via SSH**:
   - **Explanation**: The **admin** user (`cnlab01`) is prompted to enter the password (`iter123`).
   - **Purpose**: Successfully logs into the router using the **SSH** connection and admin credentials.

4. **Login as `cnlabguest` User (SSH)**:
   - **Command**: `ssh -l cnlabguest 192.168.1.1`
   - **Explanation**: The **PC** attempts to establish an **SSH** session to the router with the **guest username** **cnlabguest**.
   - **Purpose**: This will prompt for the **guest password** (`lab123`).

5. **Login to Privileged EXEC Mode as Guest**:
   - **Command**: `enable`
   - **Explanation**: The **guest** user enters **privileged EXEC mode** by typing **`enable`** and entering the **secret password** (`gm123`).
   - **Purpose**: Grants the **guest** user higher-level access to the router after entering the secret password.

---

### **Objective 2: Telnet Configuration (local login authentication without ssh)**

#### **Configuration Steps (Telnet)**:

1. **`no transport input ssh`**
   - **Explanation**: Disables **SSH** as a transport method for remote access on the VTY lines.
   - **Purpose**: Removes SSH, allowing Telnet to be configured as the remote access method.

2. **`no ip ssh version 2`**
   - **Explanation**: Disables **SSH version 2**.
   - **Purpose**: Fully disables SSH and prepares the router for Telnet access.

3. **`line vty 0 4`**
   - **Explanation**: Configures the **VTY lines** (lines 0 to 4) for remote access.
   - **Purpose**: Prepares the router to accept remote Telnet connections.

4. **`transport input telnet`**
   - **Explanation**: Enables **Telnet** as the transport method for remote access on the VTY lines.
   - **Purpose**: Configures the router to accept **Telnet** connections from remote devices.

5. **`exit`**
   - **Explanation**: Exits from the **line vty** configuration mode.
   - **Purpose**: Returns to global configuration mode after modifying the VTY lines for Telnet.

---

#### **Executing Telnet from PC**:

1. **Verify Network Connectivity:**
   - **Command**: `ping 192.168.1.1`
   - **Explanation**: The **PC** sends a **ping** to the router at IP address **192.168.1.1** to verify network connectivity.
   - **Purpose**: Ensures that the PC can reach the router and the network is functioning.

2. **Initiate Telnet Connection:**
   - **Command**: `telnet 192.168.1.1`
   - **Explanation**: Initiates a **Telnet** connection to the router at **192.168.1.1**.
   - **Purpose**: Attempts to establish a Telnet session to the router from the PC.

3. **Login as `cnlab01` User (Telnet)**:
   - **Explanation**: The **admin** user is prompted to enter the **username** and **password**.
     - Username: **cnlab01**
     - Password: **iter123**
   - **Purpose**: Provides **admin** level access to the router after login.

4. **Login as `cnlabguest` User (Telnet)**:
   - **Command**: `telnet 192.168.1.1`
   - **Explanation**: Initiates another **Telnet** session, this time logging in as the **guest** user.
     - Username: **cnlabguest**
     - Password: **lab123**
   - **Purpose**: Logs into the router using **guest** credentials.

5. **Enable Privileged EXEC Mode for Guest**:
   - **Command**: `enable`
   - **Explanation**: The **guest** user enters **privileged EXEC mode** by typing **`enable`** and entering the **secret password** (`gm123`).
   - **Purpose**: Grants **guest** user higher-level access on the router.

---

### **Summary of SSH and Telnet Configuration:**

**SSH Configuration**:
1. Created users (`cnlab01` and `cnlabguest`) with specified privilege levels and passwords.
2. Configured **local authentication** for console and remote access.
3. Enabled **SSH** for encrypted remote access, disabling Telnet for security.
4. Set up RSA encryption keys and SSH version 2 for secure communication.
5. Secured remote access via SSH for both **admin** and **guest** users.

**Telnet Configuration**:
1. Disallowed SSH and enabled **Telnet** for remote access.
2. Configured the router to accept **Telnet** connections on the **VTY lines**.
3. Verified network connectivity and successfully connected using Telnet with both **admin** and **guest** users.
4. Allowed the **guest** user to elevate privileges through the **`enable`** command using the secret password.

This configuration experiment demonstrates both secure **SSH** and less secure **Telnet** methods for remote management.
