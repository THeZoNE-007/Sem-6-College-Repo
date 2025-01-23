# Create dictionaries for key-to-value and value-to-key mappings
UPPSERCASE_key_to_value = {chr(i): i - 65 for i in range(65, 91)}  # A-Z to 0-25
UPPERCASE_value_to_key = {i - 65: chr(i) for i in range(65, 91)}  # 0-25 to A-Z

lowercase_key_to_value = {chr(i): i - 97 for i in range(97, 123)} #a-z to 0-25
lowercase_value_to_key = {i - 97: chr(i) for i in range(97, 123)} #0-25 to a-z

# Function to get value from key
def get_value(key):
    if key.isupper():
        return UPPERCASE_key_to_value.get(key, "Key not found.")
    elif key.islower():
        return lowercase_key_to_value.get(key, "Key not found.")
    else: 
        print("Something went wrong !")

# Function to get key from value
def get_key(value):
    return UPPERCASE_value_to_key.get(value % 26, "Value not found.")

plainText = input('Enter your plain text (uppercase A-Z): ')
keY = int(input('Enter the key value (integer): '))
opText = []

for char in plainText:
    if char in UPPSERCASE_key_to_value or lowercase_key_to_value:
        to_N = (get_value(char) + keY) % 26
        opText.append(to_N)

# Convert numeric values back to characters
finalRes = ''.join(get_key(value) for value in opText)
print("Encrypted text:", finalRes)
