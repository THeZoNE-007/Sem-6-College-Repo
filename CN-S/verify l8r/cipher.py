def encrypt(p,k):
  c=""
  j=0
  for i in p:
    shift = ord(k[j % len(k)]) - ord('a')
    c += chr((ord(i) - ord('a') +shift) % 26 + ord('A'))
    j+=1
  return c
  
def decrypt(c,k):
  p=""
  j=0
  for i in c:
    shift = ord(k[j % len(k)]) - ord('a')
    p += chr((ord(i) - ord('A') - shift +26 ) % 26 + ord('a'))
    j+=1
  return p
 
p = input("Input plaintext:")
k = input("Input key:")
p = "".join(p.lower().split())
print("plaintext is: ",p)
k = "".join(k.lower().split())
print("Key is: ",k)
c = encrypt(p,k)
print("e_ciphertext is: ",c)
p1 = decrypt(p,k)
print("d_plaintext is: ",p1)    
