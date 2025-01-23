# Create dictionaries for key-to-value and value-to-key mappings
key_to_value = {chr(i): i - 65 for i in range(65, 91)}  # A-Z to 0-25
value_to_key = {i - 65: chr(i) for i in range(65, 91)}  # 0-25 to A-Z

# Function to get value from key
def get_value(key):
    return key_to_value.get(key, "Key not found.")

# Function to get key from value
def get_key(value):
    return value_to_key.get(value % 26, "Value not found.")

plainText = input('Enter your plain text (uppercase A-Z): ')
keY = int(input('Enter the key value (integer): '))
opText = []

for char in plainText:
    if char in key_to_value:
        to_N = (get_value(char) + keY) % 26
        opText.append(to_N)

# Convert numeric values back to characters
finalRes = ''.join(get_key(value) for value in opText)
print("Encrypted text:", finalRes)
