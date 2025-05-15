import random
import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def calculate_n(p, q):
    return p * q

def phi(p, q):
    return (p - 1) * (q - 1)

def calculate_e(phi_n):
    e = random.randint(2, phi_n - 1)
    while math.gcd(e, phi_n) != 1:
        e = random.randint(2, phi_n - 1)
    return e

def calculate_d(e, phi_n):
    return pow(e, -1, phi_n)

def encrypt(plainText, e, n):
    cipher = ""
    for char in plainText:
        m = ord(char)
        c = pow(m, e, n)
        cipher += str(c).zfill(4) 
    return cipher

def decrypt(cipherText, d, n):
    plain = ''
    for i in range(0, len(cipherText), 4):
        block = cipherText[i:i+4]
        c = int(block)
        m = pow(c, d, n)
        plain += chr(m)
    return plain

p = int(input("Enter a large prime number P: "))
while not is_prime(p):
    print(p, "is not a prime number!!")
    p = int(input("Enter a large prime number P: "))

q = int(input("Enter a large prime number Q: "))
while not is_prime(q):
    print(q, "is not a prime number!!")
    q = int(input("Enter a large prime number Q: "))

n = calculate_n(p, q)
phi_n = phi(p, q)
e = calculate_e(phi_n)
d = calculate_d(e, phi_n)

print(f"\nPublic Key: \n\t(e={e}, n={n})")
print(f"Private Key: \n\t(d={d}, n={n})\n")

ansr = "y"
while ansr.lower() == "y":
    print("Encrypt(1) / Decrypt(2)")
    ch = int(input("Enter your choice from above: "))
    
    if ch == 1:
        plainText = input("Enter plaintext: ")
        encrypted = encrypt(plainText, e, n)
        print("Ciphertext:", encrypted)
    elif ch == 2:
        cipherText = input("Enter ciphertext: ")
        decrypted = decrypt(cipherText, d, n)
        print("Deciphered text:", decrypted)
    else:
        print("Invalid choice.")
    
    ansr = input("Do you want to continue? (y/n): ")