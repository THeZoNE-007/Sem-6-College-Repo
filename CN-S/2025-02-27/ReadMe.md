## **LAB Experiment 02**

### **Objective 2: Remote User Authentication using AAA Server (TACACS) with Telnet**

#### **Pre-requisites:**
- **x2 PCs -** PC1 IP: 10.10.10.2 ; PC2 IP: 10.10.10.3
- **x1 Server -** Server IP: 10.10.10.1
- **x1 Switch -** Above 3 connected to this Switch.
- **x1 Router -** Above switch connected to this Router (It's Router 2901 in this case).

#### **Configuration Steps (AAA with TACACS):**
Navigate to the CLI of the Router, then:
1. **`en`**
   - **Explanation**: Enters privileged EXEC mode.
   - **Purpose**: Enables execution of configuration commands.

2. **`config t`**
   - **Explanation**: Enters global configuration mode.
   - **Purpose**: Prepares the router for configuration changes.

3. **`aaa new-model`**
   - **Explanation**: Activates AAA (Authentication, Authorization, and Accounting) on the router.
   - **Purpose**: Provides centralized management for authentication.

4. **`aaa authentication login default group tacacs+ local`**
   - **Explanation**: Configures the default login authentication to use TACACS+ server first, with local authentication as a fallback.
   - **Purpose**: Ensures that if the TACACS+ server is unreachable, the router will use its local user database.

5. **`tacacs-server host <server's IP>`**
   - **Explanation**: Specifies the AAA server's IP address.
   - **Purpose**: Directs authentication requests to the TACACS+ server (replace `<server's IP>` with **10.10.10.1**).

6. **`tacacs-server key server123`**
   - **Explanation**: Sets the shared secret key for TACACS+ communications. In my case I have set `server123`, you can set yours.
   - **Purpose**: Secures the communication channel between the router and the AAA server.

7. **`line vty 0 5`**
   - **Explanation**: Enters VTY (remote access) line configuration mode.
   - **Purpose**: Prepares the lines used for remote access (Telnet).

8. **`login authentication default`**
   - **Explanation**: Applies the default AAA authentication method to the VTY lines.
   - **Purpose**: Ensures remote access sessions are authenticated via the TACACS+ server.

9. **`line console 0`**
   - **Explanation**: Enters console line configuration mode.
   - **Purpose**: Prepares the console access for AAA authentication.

10. **`login authentication default`**
    - **Explanation**: Applies AAA authentication to the console line.
    - **Purpose**: Ensures local console sessions also authenticate via the AAA server.

11. **`exit`**
    - **Explanation**: Exits line configuration mode.
    - **Purpose**: Returns to global configuration mode.

12. **`exit`**
    - **Explanation**: Exits global configuration mode.
    - **Purpose**: Completes the configuration session.

---

#### **AAA Server Configuration:**

1. **Access AAA Service:**
   - Navigate to the **Services** tab on the server.
   - Select **AAA** as the service type.

2. **Network Configurations:**
   - **Client Name**: Enter the **host name of the Router**.
   - **Client IP**: Enter the router's IP address (**10.10.10.10**).
   - **Secret**: Enter **server123** (The one we set before).
   - **Server Type**: Select **TACACS**.
   - **Explanation**: Registers the router as a TACACS client.
   - **Purpose**: Establishes a secure and authenticated connection between the router and the AAA server.

3. **User Setup:**
   - Create the following user accounts on the AAA server:
     1. **Username**: `cns1` ; **Password**: `cns123`
     2. **Username**: `cns2` ; **Password**: `cns1234`
   - **Explanation**: Configures AAA server user accounts for authentication.
   - **Purpose**: Provides valid credentials for remote access to the router.

---

#### **Verification Steps (Using Telnet):**

1. **Verify Network Connectivity:**
   - **Command**: `ping 10.10.10.1`
   - **Explanation**: PC1 sends a ping to the AAA server to confirm connectivity.
   - **Purpose**: Ensures that the network path between the PC and the server is operational.

2. **Initiate Telnet Connection:**
   - **Command**: `telnet 10.10.10.1`
   - **Explanation**: Initiates a Telnet session to the AAA server.
   - **Purpose**: Tests the AAA-based authentication process for remote access.

3. **User Authentication:**
   - **Prompt**: "User Access Verification"
   - **Username**: `cns1`
   - **Password**: `cns123`
   - **Explanation**: The AAA server validates the provided credentials.
   - **Purpose**: Grants access to the router if the credentials are correct.

4. **Note on Local Authentication:**
   - **Explanation**: If a local user (e.g., `admin` with password `cycscse`) is configured on the router, attempting to log in with these credentials will be rejected when the AAA server is active.
   - **Purpose**: Demonstrates that AAA server authentication takes precedence over local authentication. If the AAA server is disconnected, local authentication may then be valid.

---

**Summary of Objective 2:**

- Configured the router for AAA-based authentication using a TACACS+ server.
- Established secure communication between the router and the AAA server using a shared key.
- Verified remote access via Telnet, ensuring that only credentials validated by the AAA server are accepted.
- Demonstrated the overriding of local authentication when the AAA server is active.

---
### **Objective 3: Remote User Authentication using AAA Server (TACACS) with SSH**

#### **Pre-requisites:** Same setup as above objective

#### **Configuration Steps (AAA with TACACS and SSH):**

1. **`en`**
   - **Explanation**: Enters privileged EXEC mode.
   - **Purpose**: Allows execution of configuration commands.

2. **`config t`**
   - **Explanation**: Enters global configuration mode.
   - **Purpose**: Prepares the router for configuration changes.

3. **`aaa new-model`**
   - **Explanation**: Activates AAA (Authentication, Authorization, and Accounting) on the router.
   - **Purpose**: Enables centralized management for authentication.

4. **`aaa authentication login default group tacacs+ local`**
   - **Explanation**: Configures the default login authentication to use the TACACS+ server first, with local authentication as a fallback.
   - **Purpose**: Ensures that authentication is primarily handled by the TACACS+ server.

5. **`tacacs-server host 10.10.10.1`**
   - **Explanation**: Specifies the AAA server's IP address.
   - **Purpose**: Directs authentication requests to the TACACS+ server.

6. **`tacacs-server key server123`**
   - **Explanation**: Sets the shared secret key for TACACS+ communications.
   - **Purpose**: Secures the communication between the router and the AAA server.

7. **`hostname R1`**
   - **Explanation**: Sets the router’s hostname to **R1**.
   - **Purpose**: Identifies the router, which is required for SSH key generation.

8. **`ip domain-name cn.com`**
   - **Explanation**: Configures the router's domain name.
   - **Purpose**: Necessary for generating RSA keys for SSH.

9. **`crypto key generate rsa`**
   - **Explanation**: Generates an RSA key pair.
   - **Purpose**: Enables encrypted SSH communication.
   - **Prompt**: The router will ask for the key modulus size; entering a value such as **1024** bits is recommended for better security.

10. **`ip ssh version 2`**
    - **Explanation**: Configures the router to use SSH version 2.
    - **Purpose**: Provides enhanced security compared to SSH version 1.

11. **`line vty 0 5`**
    - **Explanation**: Enters the configuration mode for VTY lines 0 through 5 (remote access lines).
    - **Purpose**: Prepares the router for remote SSH access.

12. **`transport input ssh`**
    - **Explanation**: Configures the router to accept only SSH connections on the VTY lines.
    - **Purpose**: Ensures that remote access is secure and encrypted.

13. **`login authentication default`**
    - **Explanation**: Applies the default AAA authentication method (TACACS+ first, then local) to the VTY lines.
    - **Purpose**: Ensures remote SSH sessions are authenticated using the AAA server.

14. **`exit`**
    - **Explanation**: Exits the VTY line configuration mode.
    - **Purpose**: Returns to global configuration mode.

15. **`line console 0`**
    - **Explanation**: Enters the console line configuration mode.
    - **Purpose**: Prepares the router’s console access to use AAA authentication.

16. **`login authentication default`**
    - **Explanation**: Applies the default AAA authentication method to the console line.
    - **Purpose**: Ensures that even local console access is authenticated via the AAA server.

17. **`exit`**
    - **Explanation**: Exits the console line configuration mode.
    - **Purpose**: Returns to global configuration mode.

18. **`exit`**
    - **Explanation**: Exits global configuration mode.
    - **Purpose**: Completes the configuration session.

---

#### **AAA Server Configuration:**

1. **Access AAA Service:**
   - On the server, navigate to the **Services** tab and select **AAA** as the service type.

2. **Network Configurations:**
   - **Client Name**: Enter the **host name of the Router** (In this case, **R1**).
   - **Client IP**: Enter the router's IP address (In this case, **10.10.10.10**).
   - **Secret**: Enter **server123** (The one we set before).
   - **Server Type**: Choose **TACACS**.
   - **Explanation**: This registers the router as a TACACS client.
   - **Purpose**: Establishes a secure, authenticated connection between the router and the AAA server.

3. **User Setup:**
   - Create the following user accounts on the AAA server:
     1. **Username**: `cns1` ; **Password**: `iter123`
     2. **Username**: `cns2` ; **Password**: `soa1234`
   - **Explanation**: Sets up valid credentials for remote access.
   - **Purpose**: Provides accounts that will be authenticated by the AAA server when users attempt to access the router via SSH.

---

#### **Verification Steps (Using SSH):**

1. **Verify Network Connectivity:**
   - **Command**: `ping 10.10.10.10`
   - **Explanation**: PC1 sends a ping to the router's interface to confirm network connectivity.
   - **Purpose**: Ensures that the PC can reach the router.

2. **Initiate SSH Connection:**
   - **Command**: `ssh -l cns1 10.10.10.10`
   - **Explanation**: PC1 initiates an SSH session to the router using the **cns1** username.
   - **Purpose**: Tests the SSH-based AAA authentication process.

3. **User Authentication:**
   - **Prompt**: "Password:" will appear.
   - **Password**: `iter123`
   - **Explanation**: The AAA server authenticates the user credentials.
   - **Purpose**: Grants access to the router if the credentials are correct.

---

**Summary of Objective 3:**

- Configured the router for AAA-based authentication using a TACACS+ server.
- Established secure communication with the AAA server using a shared key and SSH.
- Generated RSA keys and set SSH version 2 to enable encrypted remote access.
- Applied AAA authentication to both remote (VTY) and local (console) access.
