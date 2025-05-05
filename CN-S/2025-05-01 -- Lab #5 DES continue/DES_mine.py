from Crypto.Cipher import DES
import binascii

def des_encrypt(key, plaintext):
    """
    Encrypts the plaintext using DES algorithm with 16 rounds.
    :param key: 8-byte (64-bit) key for DES encryption
    :param plaintext: 8-byte (64-bit) plaintext to encrypt
    :return: Encrypted ciphertext
    """
    cipher = DES.new(key, DES.MODE_ECB)
    ciphertext = cipher.encrypt(plaintext)
    return ciphertext

def des_decrypt(key, ciphertext):
    """
    Decrypts the ciphertext using DES algorithm with 16 rounds.
    :param key: 8-byte (64-bit) key for DES decryption
    :param ciphertext: 8-byte (64-bit) ciphertext to decrypt
    :return: Decrypted plaintext
    """
    cipher = DES.new(key, DES.MODE_ECB)
    plaintext = cipher.decrypt(ciphertext)
    return plaintext

if __name__ == "__main__":
    # Accept 64-bit key and plaintext in hexadecimal format
    key_hex = input("Enter the 64-bit key in hexadecimal (16 characters): ")
    plaintext_hex = input("Enter the 64-bit plaintext in hexadecimal (16 characters): ")

    # Convert hexadecimal inputs to bytes
    key = binascii.unhexlify(key_hex)
    plaintext = binascii.unhexlify(plaintext_hex)

    # Ensure the key and plaintext are 8 bytes (64 bits)
    if len(key) != 8 or len(plaintext) != 8:
        print("Error: Key and plaintext must be exactly 64 bits (16 hexadecimal characters).")
        exit(1)

    # Encrypt the plaintext
    ciphertext = des_encrypt(key, plaintext)
    print(f"Ciphertext (hex): {ciphertext.hex()}")

    # Decrypt the ciphertext
    decrypted_text = des_decrypt(key, ciphertext)
    print(f"Decrypted Text (hex): {decrypted_text.hex()}")
    print(f"Decrypted Text (ASCII): {decrypted_text.decode(errors='ignore')}")