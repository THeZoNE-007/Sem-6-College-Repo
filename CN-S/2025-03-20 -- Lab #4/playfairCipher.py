def is_pair(arr):
    for i in range(0, len(arr) - 1, 2):
        if arr[i] == arr[i + 1]:
            return True
    return False

def search(mat, element):
    for i in range(5):
        for j in range(5):
            if mat[i][j] == element or element in str(mat[i][j]):
                return i, j
    return -1, -1

def format_key(key, pair):
    alphabets = []
    c1, c2 = pair
    for i in range(97, 123):
        ch = chr(i)
        if ch == c1:
            alphabets.append((c1, c2))
            continue
        if ch == c2:
            continue
        alphabets.append(ch)

    matrix = [[0 for _ in range(5)] for _ in range(5)]
    i = j = 0
    for ch in key:
        if ch in alphabets:
            matrix[i][j] = ch
            alphabets.remove(ch)
            j += 1
        elif (ch == c1 or ch == c2) and (c1, c2) in alphabets:
            matrix[i][j] = (c1, c2)
            alphabets.remove((c1, c2))
            j += 1
        if j == 5:
            j = 0
            i += 1

    for item in alphabets:
        matrix[i][j] = item
        j += 1
        if j == 5:
            j = 0
            i += 1
    return matrix

def prepare_plaintext(pt):
    pt = pt.lower()
    text = list(pt)
    i = 0
    while i < len(text) - 1:
        if text[i] == text[i + 1]:
            text.insert(i + 1, 'z' if text[i] == 'x' else 'x')
        i += 2
    if len(text) % 2 != 0:
        text.append('x' if text[-1] == 'z' else 'z')
    return [(text[i], text[i + 1]) for i in range(0, len(text), 2)]

def prepare_ciphertext(ct):
    ct = ct.lower()
    return [(ct[i], ct[i + 1]) for i in range(0, len(ct), 2)]

def swap(pair_list, matrix, pair, mode):
    result = ''
    c1, c2 = pair
    for a, b in pair_list:
        x1, y1 = search(matrix, a)
        x2, y2 = search(matrix, b)

        if x1 == x2:  # Same row
            if mode == 'e':
                y1, y2 = (y1 + 1) % 5, (y2 + 1) % 5
            else:
                y1, y2 = (y1 - 1) % 5, (y2 - 1) % 5
        elif y1 == y2:  # Same column
            if mode == 'e':
                x1, x2 = (x1 + 1) % 5, (x2 + 1) % 5
            else:
                x1, x2 = (x1 - 1) % 5, (x2 - 1) % 5
        else:  # Rectangle swap
            y1, y2 = y2, y1

        result += c1 if matrix[x1][y1] == pair else matrix[x1][y1]
        result += c1 if matrix[x2][y2] == pair else matrix[x2][y2]
    return result

# ------------------- MAIN -------------------

mode = input("Do you want to encrypt or decrypt? (e/d): ").lower().strip()
while mode not in ['e', 'd']:
    mode = input("Invalid choice. Please enter 'e' for encryption or 'd' for decryption: ").lower().strip()

key = input("Enter your key: ").lower()
key = ''.join(filter(str.isalpha, key))

print("Which two consecutive characters do you want to keep in the same position?")
while True:
    c1 = input("Enter first character: ").lower()
    c2 = input("Enter second character: ").lower()
    if ord(c2) - ord(c1) == 1:
        break
    print("Please enter consecutive alphabets (e.g., a b or p q).")

matrix = format_key(key, (c1, c2))
print("\nGenerated 5x5 Matrix:")
for row in matrix:
    print(row)

if mode == 'e':
    pt = input("\nEnter the plain text: ").lower()
    pt = ''.join(filter(str.isalpha, pt))
    pairs = prepare_plaintext(pt)
    print("Prepared Digraphs:", pairs)
    cipher_text = swap(pairs, matrix, (c1, c2), mode)
    print("\nEncrypted Cipher Text:", cipher_text)

else:
    ct = input("\nEnter the cipher text: ").lower()
    ct = ''.join(filter(str.isalpha, ct))
    pairs = prepare_ciphertext(ct)
    print("Prepared Digraphs:", pairs)
    plain_text = swap(pairs, matrix, (c1, c2), mode)
    print("\nDecrypted Plain Text:", plain_text)


"""
OUTPUT:-

Do you want to encrypt or decrypt? (e/d): e
Enter your key: ardhendu
Which two consecutive characters do you want to keep in the same position?
Enter first character: i
Enter second character: j

Generated 5x5 Matrix:
['a', 'r', 'd', 'h', 'e']
['n', 'u', 'b', 'c', 'f']
['g', ('i', 'j'), 'k', 'l', 'm']
['o', 'p', 'q', 's', 't']
['v', 'w', 'x', 'y', 'z']

Enter the plain text: hello
Prepared Diagraphs: [('h', 'e'), ('l', 'x'), ('l', 'o')]

Encrypted Cipher Text: eakygs

"""
