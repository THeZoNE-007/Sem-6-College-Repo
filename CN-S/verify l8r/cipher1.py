def create_key_matrix(key):                 # Creates a 5x5 Playfair cipher matrix from a key.
    key = key.upper().replace("J", "I")     # Replace the character J with I in keyword provided.
    matrix = []                            # keymatrix initially empty.
    for ch in key:                          # Appends keyword's characters into keymatrix.
        if ch.isalpha() and ch not in matrix:
            matrix.append(ch)
    for ch in "ABCDEFGHIKLMNOPQRSTUVWXYZ":  # Appends rest of the alphabets into keymatrix
        if ch not in matrix:
            matrix.append(ch)
    # Upto this the keymatrix is a 1D list. Now create a 2D list.
    keymatrix = []
    for i in range(0,25,5):
      keymatrix.append(matrix[i:i+5])
    return keymatrix
def find_char_position(matrix, ch):   # Finds the row and column of a character in the matrix.
    for i in range(len(matrix)):
      for j in range(len(matrix[i])):
        if (matrix[i][j] == ch):
            return i,j
    return None  # Should not happen if the character is in the matrix
def prepare_plaintext(plaintext):     # Prepares the plaintext for encryption/decryption.
    plaintext = plaintext.upper().replace("J", "I")   # Replace J with I in plaintext.
    plaintext = "".join(filter(str.isalpha, plaintext))  # Remove non-alphabetic characters

    pairs = []          # Empty pairs list
    i = 0
    while i < len(plaintext):         # Runs loop for all positions of plaintext
        pair = plaintext[i:i + 2]     # Gets first two characters in the temporary variable pair.
        if len(pair) == 2 and pair[0] == pair[1]:   # If length of the pair is 2 (last pair possibly have only one character) and both the characters are same
          pairs.append(pair[0] + "X") # append to the pairs list 1st character and X.
          i+=1                        # in this case counter will be incremented by one only as only one characters is considered
        else:                         # Otherwise
          pairs.append(pair)          # Append the pair of characters to pairs list.
          i += 2                      # in this case counter will be incremented by 2 as both the characters are considered
    if len(pairs[len(pairs)-1]) % 2 != 0: # Adds padding 'X' in the last pair if it's length is odd
        pairs[len(pairs)-1] += 'X'
    return pairs
def encryption(plaintext, key):       # Encrypts the plaintext using the Playfair cipher.
    keymatrix = create_key_matrix(key)      # create_key_matrix method called
    pairs = prepare_plaintext(plaintext)    # prepare_plaintext method called
    ciphertext = ""                         # empty ciphertext string initialized

    for pair in pairs:
        row1, col1 = find_char_position(keymatrix, pair[0])   # Finds position of 1st character of the pair
        row2, col2 = find_char_position(keymatrix, pair[1])   # Finds position of 2nd character of the pair

        if row1 == row2:                    # Both characters are in same row
            ciphertext += keymatrix[row1][(col1 + 1) % 5]     # Replaced by the characters to its right
            ciphertext += keymatrix[row2][(col2 + 1) % 5]     # Replaced by the characters to its right
        elif col1 == col2:                  # Both characters are in same column
            ciphertext += keymatrix[(row1 + 1) % 5][col1]     # Replaced by the characters below it
            ciphertext += keymatrix[(row2 + 1) % 5][col2]     # Replaced by the characters below it
        else:                               # Both characters are in different row and column
            ciphertext += keymatrix[row1][col2]               # Replaced by the characters in its row but others column
            ciphertext += keymatrix[row2][col1]               # Replaced by the characters in its row but others column

    return ciphertext
def decryption(ciphertext, key):         # Decrypts the ciphertext using the Playfair cipher.
    keymatrix = create_key_matrix(key)      # create_key_matrix method called
    pairs = []
    for i in range(0, len(ciphertext), 2):  # Generates the pairs list from the ciphertext
      pairs.append(ciphertext[i:i + 2])

    plaintext = ""

    for pair in pairs:
        row1, col1 = find_char_position(keymatrix, pair[0])   # Finds position of 1st character of the pair
        row2, col2 = find_char_position(keymatrix, pair[1])   # Finds position of 2nd character of the pair

        if row1 == row2:                    # Both characters are in same row
            plaintext += keymatrix[row1][(col1 - 1) % 5]      # Replaced by the characters to its left
            plaintext += keymatrix[row2][(col2 - 1) % 5]      # Replaced by the characters to its left
        elif col1 == col2:                  # Both characters are in same column
            plaintext += keymatrix[(row1 - 1) % 5][col1]      # Replaced by the characters above it
            plaintext += keymatrix[(row2 - 1) % 5][col2]      # Replaced by the characters above it
        else:                               # Both characters are in different row and column
            plaintext += keymatrix[row1][col2]                # Replaced by the characters in its row but others column
            plaintext += keymatrix[row2][col1]                # Replaced by the characters in its row but others column

    return plaintext
key = input("Enter keyword: ")
plaintext = input("Enter plaintext: ")
print(create_key_matrix(key))
print('Paired plaintext is',prepare_plaintext(plaintext))
ciphertext = encryption(plaintext, key)
print("Ciphertext:", ciphertext)
decrypted_plaintext = decryption(ciphertext, key)
print("Decrypted plaintext:", decrypted_plaintext)
