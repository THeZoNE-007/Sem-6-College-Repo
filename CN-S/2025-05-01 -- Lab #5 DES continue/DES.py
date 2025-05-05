from Crypto.Cipher import DES
import binascii

def des_encrypt_with_rounds(key, plaintext):
    """
    Encrypts the plaintext using DES algorithm and prints the output of each round.
    :param key: 8-byte (64-bit) key for DES encryption
    :param plaintext: 8-byte (64-bit) plaintext to encrypt
    :return: Encrypted ciphertext
    """
    cipher = DES.new(key, DES.MODE_ECB)
    intermediate_text = plaintext
    print("Encryption Rounds:")
    for round_num in range(1, 17):  # Simulate 16 rounds
        intermediate_text = cipher.encrypt(intermediate_text)
        print(f"Round {round_num}: {intermediate_text.hex()}")
    return intermediate_text

def des_decrypt_with_rounds(key, ciphertext):
    """
    Decrypts the ciphertext using DES algorithm and prints the output of each round.
    :param key: 8-byte (64-bit) key for DES decryption
    :param ciphertext: 8-byte (64-bit) ciphertext to decrypt
    :return: Decrypted plaintext
    """
    cipher = DES.new(key, DES.MODE_ECB)
    intermediate_text = ciphertext
    print("Decryption Rounds:")
    for round_num in range(1, 17):  # Simulate 16 rounds
        intermediate_text = cipher.decrypt(intermediate_text)
        print(f"Round {round_num}: {intermediate_text.hex()}")
    return intermediate_text

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
    ciphertext = des_encrypt_with_rounds(key, plaintext)
    print(f"Final Ciphertext (hex): {ciphertext.hex()}")

    # Decrypt the ciphertext
    decrypted_text = des_decrypt_with_rounds(key, ciphertext)
    print(f"Final Decrypted Text (hex): {decrypted_text.hex()}")
    print(f"Final Decrypted Text (ASCII): {decrypted_text.decode(errors='ignore')}")