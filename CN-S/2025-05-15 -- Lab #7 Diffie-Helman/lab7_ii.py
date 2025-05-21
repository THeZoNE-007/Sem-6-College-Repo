import math
import random
import hashlib

def keyGeneration():
    p = int(input("Enter 1st large prime p: "))
    q = int(input("Enter 2nd large prime q: "))
    n = p * q
    phi_n = (p - 1) * (q - 1)

    e = int(input(f"Choose a public key 'e' (1 < e < {phi_n}) such that gcd(e, {phi_n}) = 1: "))
    while math.gcd(e, phi_n) != 1 or not (1 < e < phi_n):
        e = int(input(f"Invalid. Choose 'e' again (1 < e < {phi_n}) and gcd(e, {phi_n}) = 1: "))

    d = pow(e, -1, phi_n)
    return e, d, n

def hash_message(message, n):
    sha256 = hashlib.sha256()
    sha256.update(message.encode('utf-8'))
    hash_bytes = sha256.digest()
    hash_int_full = int.from_bytes(hash_bytes, byteorder='big')
    # Modulo to ensure hash fits within modulus n
    hash_int = hash_int_full % n
    return hash_int

def sign_hash(hash_int, d, n):
    return pow(hash_int, d, n)

def verify_signature(signature, original_message, e, n):
    original_hash = hash_message(original_message, n)
    decrypted_hash = pow(signature, e, n)

    print("\n--- Verifying Signature ---")
    print("Original Hash (mod n):   ", original_hash)
    print("Decrypted Hash (mod n):  ", decrypted_hash)

    if decrypted_hash == original_hash:
        print("Signature is VALID. Message is AUTHENTIC.")
        return True
    else:
        print("Signature is INVALID. Message may be FORGED.")
        return False

# --- Main Flow ---
e, d, n = keyGeneration()
print(f"\nPublic Key (e, n): ({e}, {n})")
print(f"Private Key (d, n): ({d}, {n})\n")

message = input("Enter the TEXT message to sign: ")
hash_value = hash_message(message, n)

signature = sign_hash(hash_value, d, n)
print(f"\nDigital Signature: {signature}\n")

# Verify signature
verify_signature(signature, message, e, n)

"""
OUTPUT:

Enter 1st large prime p: 3557
Enter 2nd large prime q: 2579
Choose a public key 'e' (1 < e < 9167368) such that gcd(e, 9167368) = 1: 65537

Public Key (e, n): (65537, 9173503)
Private Key (d, n): (4922825, 9173503)

Enter the TEXT message to sign: Loki of Asgard

Digital Signature: 2028327


--- Verifying Signature ---
Original Hash (mod n):    6324800
Decrypted Hash (mod n):   6324800
Signature is VALID. Message is AUTHENTIC.

"""