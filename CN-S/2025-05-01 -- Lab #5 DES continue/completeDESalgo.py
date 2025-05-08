from Crypto.Cipher import DES

def des_encrypt(plaintext, key):
    cipher = DES.new(key, DES.MODE_ECB)
    ciphertext = cipher.encrypt(plaintext)
    return ciphertext

def des_decrypt(ciphertext, key):
    cipher = DES.new(key, DES.MODE_ECB)
    decrypted_plaintext = cipher.decrypt(ciphertext)
    return decrypted_plaintext

def main():
    # Given hex string for key and plaintext
    hex_str = "0123456789ABCDEF"
    key = bytes.fromhex(hex_str)
    plaintext = bytes.fromhex(hex_str)

    print(f"Key (hex): {key.hex()}")
    print(f"Plaintext (hex): {plaintext.hex()}")

    ciphertext = des_encrypt(plaintext, key)
    print(f"Ciphertext (hex): {ciphertext.hex()}")

    decrypted_plaintext = des_decrypt(ciphertext, key)
    print(f"Decrypted Plaintext (hex): {decrypted_plaintext.hex()}")

    # Check if decrypted plaintext matches original plaintext
    if decrypted_plaintext == plaintext:
        print("Decryption successful, plaintext matches!")
    else:
        print("Decryption failed, plaintext does not match.")

if __name__ == "__main__":
    main()


"""
OUTPUT:-

Enter the key (hex): 0123456789abcdef
Enter the plaintext (hex): 0123456789abcdef
Ciphertext (hex): 56cc09e7cfdc4cef
Decrypted Plaintext (hex): 0123456789abcdef
Decryption successful, plaintext matches!

"""

