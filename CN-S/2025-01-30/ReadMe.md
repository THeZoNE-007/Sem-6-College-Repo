## **LAB Experiment 01**

### **Objective 3: SSH Configuration (local login authentication with ssh)**

#### **Pre-requisites:**
- **x1 PCs -** PC's IP: 192.168.1.10
- **x1 Switch**
- **x1 Router -** Router's IP: 192.168.1.1
- All three connected as shown in given picture.

#### **Configuration Steps (SSH)**:
- Navigate to the CLI of the Router, then:
1. **`en`**
   - **Explanation**: Enters privileged EXEC mode.
   - **Purpose**: Enables execution of configuration commands.

2. **`config t`**
   - **Explanation**: Enters global configuration mode.
   - **Purpose**: Prepares the router for configuration changes.

3. **`username cnlab01 privilege 15 secret iter123`**
   - **Explanation**: Creates an **admin user** named **cnlab01** with full administrative privileges (privilege level 15) and sets a secure password **iter123** for login.
   - **Purpose**: Allows full administrative access to the router with a secure password.

4. **`username cnlabguest privilege 1 secret lab123`**
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
---

### **Objective 2: Telnet Configuration (local login authentication without ssh)**

#### **Note:**
Since we are doing this on the same router, we are just going to remove the ssh commands that we wrote above and put telnet's commands instead. If you are doing in a completely new router that hasn't been configured, you can follow the same steps as done previously but replacing configurations of ssh with telnet's. Otherwise just log in as **admin** and start writing from Command #2 below.

#### **Pre-requisites:** Same as above !!

#### **Configuration Steps (Telnet)**:

- Navigate to the CLI of the Router, then:
1. **`en`**
   - **Explanation**: Enters privileged EXEC mode.
   - **Purpose**: Enables execution of configuration commands.

2. **`config t`**
   - **Explanation**: Enters global configuration mode.
   - **Purpose**: Prepares the router for configuration changes.

3. **`line vty 0 4`**
   - **Explanation**: Configures the **VTY lines** (lines 0 to 4) for remote access.
   - **Purpose**: Prepares the router to accept remote Telnet connections.

4. **`no transport input ssh`**
   - **Explanation**: Disables **SSH** as a transport method for remote access on the VTY lines.
   - **Purpose**: Removes SSH, allowing Telnet to be configured as the remote access method.

5. **`exit`**
    - **Explanation**: Exits line configuration mode.
    - **Purpose**: Returns to global configuration mode.

6. **`no ip ssh version 2`**
   - **Explanation**: Disables **SSH version 2**.
   - **Purpose**: Fully disables SSH and prepares the router for Telnet access.

7. **`do write`**
   - **Explanation**: Saves the current running configuration to the startup configuration.
   - **Purpose**: Ensures that changes are retained after a reboot.

8. **`do showrun`**
   - **Explanation**: To display the current active configuration of the router.
   - **Purpose**: To verify that we have successfully removed the ssh commands.

9. **`line vty 0 4`**
   - **Explanation**: Configures **VTY lines (0-4)** for remote access (via Telnet or SSH).
   - **Purpose**: Enables remote management through VTY lines.

10. **`transport input telnet`**
   - **Explanation**: Enables **Telnet** as the transport method for remote access on the VTY lines.
   - **Purpose**: Configures the router to accept **Telnet** connections from remote devices.

11. **`exit`**
   - **Explanation**: Exits from the line configuration mode.
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
   - **Explanation**: This **admin** user is prompted to enter the **username** and **password**.
     - Username: **cnlab01**
     - Password: **iter123**
   - **Purpose**: Provides **admin** level access to the router after login.

4. **Login as `cnlabguest` User (Telnet)**:
   - **Command**: `telnet 192.168.1.1`
   - **Explanation**: Initiates another **Telnet** session, this time logging in as the **guest** user.
     - Username: **cnlabguest**
     - Password: **lab123**
   - **Purpose**: Logs into the router using **guest** credentials.

---

### **Entering Privileged EXEC Mode as a Guest User:**
- It's related to telnet part, just for show only, not part of objective.

#### **Router configuration:**
- We navigate to CLI of Router.
- This time we login using **guest** credentials.

1. **`config t`**
   - **Explanation**: Enters global configuration mode.
   - **Purpose**: Prepares the router for configuration changes.

2. **`enable secret <secret key>`**
   - **Explanation**: To set a highly secure password that allows access to privileged EXEC mode on a device. Replace `secret key` with your own key (eg: `hello`).
   - **Purpose**: To enable **admin** access on **guest** users.

---

#### **Checking through PC:**

1. **Enable Privileged EXEC Mode for Guest**:
   - Namvigate to command prompt from the PC and type the below command.
   - **Command**: `enable`
   - **Explanation**: The **guest** user enters **privileged EXEC mode** by typing the command **`enable`** and entering the **secret password** (`hello`).
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
