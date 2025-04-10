import binascii

def left_rotate(n, b):
    return ((n << b) | (n >> (32 - b))) & 0xFFFFFFFF

def des_encrypt(plaintext, key):
    # Convert plaintext and key to 8-byte integers
    plaintext = int.from_bytes(plaintext, 'big')
    key = int.from_bytes(key, 'big')

    # Initialize S-boxes
    sboxes = [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 7, 0],
        [7, 12, 1, 10, 15, 4, 2, 11, 6, 8, 3, 13, 9, 14, 0, 5],
        [10, 2, 8, 4, 7, 1, 12, 11, 9, 5, 3, 13, 6, 14, 15, 0],
        [12, 1, 10, 15, 4, 7, 5, 2, 8, 14, 9, 11, 6, 3, 13, 0],
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 10, 0, 1, 13, 11, 6, 4],                    
        [7, 15, 2, 8, 12, 3, 10, 1, 9, 11, 6, 13, 4, 5, 0, 14],                    
        [12, 1, 10, 15, 9, 2, 7, 11, 14, 5, 8, 13, 3, 4, 6, 0]                     
    ]                                                                              
                                                                                   
    # Expand key                                                                   
    expanded_key = []                                                              
    for i in range(16):                                                            
        expanded_key.append((key >> (i * 4)) & 0xF)                                
                                                                                   
    # Initialize round keys                                                        
    round_keys = []                                                                
    for i in range(16):                                                            
        round_key = 0                                                              
        for j in range(16):                                                        
            round_key = ((round_key << 1) | (round_key >> 31)) ^ expanded_key[j]   
        round_keys.append(round_key)                                               
                                                                                   
    # Initialize state array                                                       
    state = [plaintext >> (i * 8) & 0xFF for i in range(16)]                       
                                                                                   
    # Perform 16 rounds                                                            
    for round_num in range(16):                                                    
        # SubBytes                                                                 
        for i in range(8):                                                         
            sbox_index = state[i] // 256                                           
            sbox_value = state[i] % 256                                            
            state[i] = (sbox_index << 8) | sboxes[round_num][sbox_value]           
                                                                                   
        # ShiftRows                                                                
        state = [state[i] for i in range(8)] + [state[i] for i in range(8, 16)]    
                                                                                   
        # MixColumns                                                               
        if round_num < 15:                                                         
            temp = []                                                              
            for i in range(64):                                                    
                row = (i // 8) * 8 + (i % 8)                                       
                col = i % 8                                                        
                temp.append(                                                       
                    (                                                              
                        (round_keys[round_num] >> col) & 0x1F                      
                        ^ ((round_keys[round_num] >> (col + 4)) & 0xF)             
                        ^ ((round_keys[round_num] >> (col + 8)) & 0x3)             
                        ^ ((round_keys[round_num] >> (col + 12)) & 0xC)            
                        ^ ((round_keys[round_num] >> (col + 16)) & 0x30)           
                        ^ ((round_keys[round_num] >> (col + 20)) & 0xC0)           
                        ^ ((round_keys[round_num] >> (col + 24)) & 0x300)          
                        ^ ((round_keys[round_num] >> (col + 28)) & 0xC00)          
                    ) << col                                                       
                )                                                                  
            state = temp                                                           
                                                                                   
    # Convert final state back to bytes                                            
    ciphertext = ''.join(chr(state[i]) for i in range(16))                         
                                                                                   
    return binascii.hexlify(ciphertext.encode()).decode()                          
                                                                                   
def des_decrypt(ciphertext, key):                                                  
    return des_encrypt(ciphertext, key)                                            
                                                                                   
# Example usage                                                                    
key = b'0123456789abcdef'                                                          
plaintext = b'This is a secret message'                                            
                                                                                   
ciphertext = des_encrypt(plaintext, key)                                           
print(f"Encrypted: {ciphertext}")                                                  
                                                                                   
decrypted_text = des_decrypt(ciphertext, key)                                      
print(f"Decrypted: {decrypted_text}")
