import binascii

# Example permutation and substitution functions (simplified for demonstration)
def initial_permutation(block):
    # Simplified initial permutation (identity for demonstration)
    return block

def final_permutation(block):
    # Simplified final permutation (identity for demonstration)
    return block

def feistel_function(right, subkey):
    # Simplified Feistel function: XOR with subkey
    return bytes([b ^ k for b, k in zip(right, subkey)])

def generate_round_keys(key):
    # Simplified key schedule: Use the same key for all rounds
    return [key] * 16

def des_encrypt(plaintext, key):
    """
    Encrypts the plaintext using DES with 16 Feistel rounds.
    :param plaintext: 8-byte (64-bit) plaintext
    :param key: 8-byte (64-bit) key
    :return: Encrypted ciphertext
    """
    # Initial permutation
    block = initial_permutation(plaintext)

    # Split into left and right halves
    left, right = block[:4], block[4:]

    # Generate round keys
    round_keys = generate_round_keys(key)

    print("Encryption Rounds:")
    # Perform 16 Feistel rounds
    for round_num, subkey in enumerate(round_keys, start=1):
        new_right = bytes([l ^ r for l, r in zip(left, feistel_function(right, subkey))])
        left, right = right, new_right
        print(f"Round {round_num}: Left = {left.hex()}, Right = {right.hex()}")

    # Combine halves and apply final permutation
    combined = right + left  # Swap left and right
    ciphertext = final_permutation(combined)
    return ciphertext

def des_decrypt(ciphertext, key):
    """
    Decrypts the ciphertext using DES with 16 Feistel rounds.
    :param ciphertext: 8-byte (64-bit) ciphertext
    :param key: 8-byte (64-bit) key
    :return: Decrypted plaintext
    """
    # Initial permutation
    block = initial_permutation(ciphertext)

    # Split into left and right halves
    left, right = block[:4], block[4:]

    # Generate round keys (reverse order for decryption)
    round_keys = generate_round_keys(key)[::-1]

    print("Decryption Rounds:")
    # Perform 16 Feistel rounds
    for round_num, subkey in enumerate(round_keys, start=1):
        new_right = bytes([l ^ r for l, r in zip(left, feistel_function(right, subkey))])
        left, right = right, new_right
        print(f"Round {round_num}: Left = {left.hex()}, Right = {right.hex()}")

    # Combine halves and apply final permutation
    combined = right + left  # Swap left and right
    plaintext = final_permutation(combined)
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