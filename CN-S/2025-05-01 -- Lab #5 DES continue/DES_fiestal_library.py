from Crypto.Cipher import DES
import binascii

def feistel_function(right, subkey):
    """
    Feistel function using DES encryption for the right half.
    :param right: 4-byte (32-bit) right half of the block
    :param subkey: 8-byte (64-bit) subkey
    :return: 4-byte (32-bit) output
    """
    cipher = DES.new(subkey, DES.MODE_ECB)
    # Encrypt the right half using the subkey
    encrypted = cipher.encrypt(right + b'\x00' * 4)  # Pad to 8 bytes
    return encrypted[:4]  # Return only the first 4 bytes

def generate_round_keys(key):
    """
    Generate 16 round keys from the main key.
    :param key: 8-byte (64-bit) key
    :return: List of 16 subkeys
    """
    # Simplified key schedule: Rotate the key for each round
    round_keys = []
    for i in range(16):
        round_keys.append(key[i % len(key):] + key[:i % len(key)])
    return round_keys

def des_encrypt(plaintext, key):
    """
    Encrypts the plaintext using DES with 16 Feistel rounds.
    :param plaintext: 8-byte (64-bit) plaintext
    :param key: 8-byte (64-bit) key
    :return: Encrypted ciphertext
    """
    # Split into left and right halves
    left, right = plaintext[:4], plaintext[4:]

    # Generate round keys
    round_keys = generate_round_keys(key)

    print("Encryption Rounds:")
    # Perform 16 Feistel rounds
    for round_num, subkey in enumerate(round_keys, start=1):
        new_right = bytes([l ^ r for l, r in zip(left, feistel_function(right, subkey))])
        left, right = right, new_right
        print(f"Round {round_num}: Left = {left.hex()}, Right = {right.hex()}")

    # Combine halves
    ciphertext = right + left  # Swap left and right
    return ciphertext

def des_decrypt(ciphertext, key):
    """
    Decrypts the ciphertext using DES with 16 Feistel rounds.
    :param ciphertext: 8-byte (64-bit) ciphertext
    :param key: 8-byte (64-bit) key
    :return: Decrypted plaintext
    """
    # Split into left and right halves
    left, right = ciphertext[:4], ciphertext[4:]

    # Generate round keys (reverse order for decryption)
    round_keys = generate_round_keys(key)[::-1]

    print("Decryption Rounds:")
    # Perform 16 Feistel rounds
    for round_num, subkey in enumerate(round_keys, start=1):
        new_right = bytes([l ^ r for l, r in zip(left, feistel_function(right, subkey))])
        left, right = right, new_right
        print(f"Round {round_num}: Left = {left.hex()}, Right = {right.hex()}")

    # Combine halves
    plaintext = right + left  # Swap left and right
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
    ciphertext = des_encrypt(plaintext, key)
    print(f"Final Ciphertext (hex): {ciphertext.hex()}")

    # Decrypt the ciphertext
    decrypted_text = des_decrypt(ciphertext, key)
    print(f"Final Decrypted Text (hex): {decrypted_text.hex()}")
    print(f"Final Decrypted Text (ASCII): {decrypted_text.decode(errors='ignore')}")