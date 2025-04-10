def create_key_matrix(key):                
    key = key.upper().replace("J", "I")    
    matrix = []                            
    for ch in key:                          
        if ch.isalpha() and ch not in matrix:
            matrix.append(ch)
    for ch in "ABCDEFGHIKLMNOPQRSTUVWXYZ":  
        if ch not in matrix:
            matrix.append(ch)
    
    keymatrix = []
    for i in range(0,25,5):
      keymatrix.append(matrix[i:i+5])
    return keymatrix
def find_char_position(matrix, ch):  
    for i in range(len(matrix)):
      for j in range(len(matrix[i])):
        if (matrix[i][j] == ch):
            return i,j
    return None  
def prepare_plaintext(plaintext):     
    plaintext = plaintext.upper().replace("J", "I")   
    plaintext = "".join(filter(str.isalpha, plaintext))  

    pairs = []          
    i = 0
    while i < len(plaintext):        
        pair = plaintext[i:i + 2]     
        if len(pair) == 2 and pair[0] == pair[1]:   
          pairs.append(pair[0] + "X") 
          i+=1                       
        else:                         
          pairs.append(pair)         
          i += 2                      
    if len(pairs[len(pairs)-1]) % 2 != 0: 
        pairs[len(pairs)-1] += 'X'
    return pairs
def encryption(plaintext, key):       
    keymatrix = create_key_matrix(key)      
    pairs = prepare_plaintext(plaintext)    
    ciphertext = ""                         

    for pair in pairs:
        row1, col1 = find_char_position(keymatrix, pair[0])   
        row2, col2 = find_char_position(keymatrix, pair[1])   

        if row1 == row2:                    
            ciphertext += keymatrix[row1][(col1 + 1) % 5]     
            ciphertext += keymatrix[row2][(col2 + 1) % 5]     
        elif col1 == col2:                  
            ciphertext += keymatrix[(row1 + 1) % 5][col1]     
            ciphertext += keymatrix[(row2 + 1) % 5][col2]     
        else:                               
            ciphertext += keymatrix[row1][col2]               
            ciphertext += keymatrix[row2][col1]               

    return ciphertext
def decryption(ciphertext, key):         
    keymatrix = create_key_matrix(key)      
    pairs = []
    for i in range(0, len(ciphertext), 2):  
      pairs.append(ciphertext[i:i + 2])

    plaintext = ""

    for pair in pairs:
        row1, col1 = find_char_position(keymatrix, pair[0])   
        row2, col2 = find_char_position(keymatrix, pair[1])   

        if row1 == row2:                    
            plaintext += keymatrix[row1][(col1 - 1) % 5]      
            plaintext += keymatrix[row2][(col2 - 1) % 5]      
        elif col1 == col2:                  
            plaintext += keymatrix[(row1 - 1) % 5][col1]      
            plaintext += keymatrix[(row2 - 1) % 5][col2]      
        else:                               
            plaintext += keymatrix[row1][col2]                
            plaintext += keymatrix[row2][col1]                

    return plaintext
key = input("Enter keyword: ")
plaintext = input("Enter plaintext: ")
print(create_key_matrix(key))
print('Paired plaintext is',prepare_plaintext(plaintext))
ciphertext = encryption(plaintext, key)
print("Ciphertext:", ciphertext)
decrypted_plaintext = decryption(ciphertext, key)
print("Decrypted plaintext:", decrypted_plaintext)
