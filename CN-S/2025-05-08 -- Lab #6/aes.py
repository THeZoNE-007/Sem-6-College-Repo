from Crypto.Cipher import AES
import binascii

def encryption(aes, P, key):
    while (len(P) % 16 != 0):
        P += " "
    P = P.encode()            
    C = aes.encrypt(P)       
    C = binascii.hexlify(C)   
    C = C.decode()             
    return C

def decryption(aes, C, key):
    C = binascii.unhexlify(C)   
    P1 = aes.decrypt(C)        
    P1 = P1.decode().strip()    
    return P1;

key = input("Enter key: ")
P = input("Enter plaintext: ")
print("Plaintext is: ",P)
key = key.encode()            
aes_cipher = AES.new(key, AES.MODE_ECB) 

C = encryption(aes_cipher, P, key)      
print("Ciphertext after encryption: ",C)

P1 = decryption(aes_cipher, C, key)     
print("Plaintext after decryption: ",P1)