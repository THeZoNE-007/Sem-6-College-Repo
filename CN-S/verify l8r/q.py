from Crypto.Cipher import DES
import binascii
def encryption(des,P,key):
    while(len(P) %8 !=0):
        P+=" "
    P=P.encode()
    C=des.encrypt(P)
    C=binascii.hexlify(C)
    C=C.decode()
    return C
def decrpyption(des,C,key):
    C=binascii.unhexlify(C)
    P1=des.decrypt(C)
    P1=P1.decode().strip()
    return P1;
key=input("Enter key: ")
P=input("Enter plaintext: ")
print("Plaintext is: ",P)
key=key.encode()
des_cipher=DES.new(key,DES.MODE_ECB)
C=encryption(des_cipher,P,key)
print("Plaintext after encryptioN",C)
p1=decrpyption(des_cipher,C,key)
print("Plaintext after decryption",p1)
