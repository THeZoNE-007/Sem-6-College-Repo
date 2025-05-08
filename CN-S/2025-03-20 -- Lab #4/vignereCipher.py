def generate_key(message, keyword):
    keyword = keyword.lower()
    key = list(keyword)
    if len(message) == len(key):
        return "".join(key)
    else:
        for i in range(len(message) - len(key)):
            key.append(keyword[i % len(keyword)])
    return "".join(key)

def encrypt_vigenere(message, key):
    cipher_text = ""
    for i in range(len(message)):
        if message[i].isalpha():
            shift = (ord(message[i]) - ord('a') + ord(key[i]) - ord('a')) % 26
            cipher_text += chr(shift + ord('a'))
        else:
            cipher_text += message[i]
    return cipher_text

def decrypt_vigenere(cipher_text, key):
    original_text = ""
    for i in range(len(cipher_text)):
        if cipher_text[i].isalpha():
            shift = (ord(cipher_text[i]) - ord(key[i]) + 26) % 26
            original_text += chr(shift + ord('a'))
        else:
            original_text += cipher_text[i]
    return original_text

# ------------------- MAIN -------------------

mode = input("Do you want to encrypt or decrypt? (e/d): ").lower().strip()
while mode not in ['e', 'd']:
    mode = input("Invalid choice. Please enter 'e' for encryption or 'd' for decryption: ").lower().strip()

message = input("Enter the message: ").lower()
keyword = input("Enter the keyword: ").lower()
keyword = ''.join(filter(str.isalpha, keyword))
message = ''.join(filter(str.isalpha, message))

key = generate_key(message, keyword)

if mode == 'e':
    cipher_text = encrypt_vigenere(message, key)
    print("\nEncrypted Cipher Text:", cipher_text)
else:
    plain_text = decrypt_vigenere(message, key)
    print("\nDecrypted Plain Text:", plain_text)


"""
OUTPUT:-

Do you want to encrypt or decrypt? (e/d): e
Enter the message: attack
Enter the keyword: lemon

Encrypted Cipher Text: lxfopv

"""