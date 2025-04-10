from Crypto.Cipher import AES
import binascii

# Encryption function
def encryption(aes, P):
    # Padding to ensure the plaintext length is a multiple of 16
    while len(P) % 16 != 0:
        P += " "
    P = P.encode()  # Convert the string to bytes
    C = aes.encrypt(P)  # Encrypt the plaintext
    C = binascii.hexlify(C)  # Convert binary C to hexadecimal
    C = C.decode()  # Convert the hexadecimal to a string
    return C

# Decryption function
def decryption(aes, C):
    C = binascii.unhexlify(C)  # Convert the hex string back to binary
    P1 = aes.decrypt(C)  # Decrypt the ciphertext
    P1 = P1.decode().strip()  # Convert binary back to string and remove padding
    return P1

# Example usage
key = b'Sixteen byte key'  # Must be 16 bytes for AES
cipher = AES.new(key, AES.MODE_ECB)  # Using ECB mode (for simplicity)

# Encrypt
plaintext = "This is a secret"
encrypted = encryption(cipher, plaintext)
print("Encrypted:", encrypted)

# Decrypt
decrypted = decryption(cipher, encrypted)
print("Decrypted:", decrypted)

