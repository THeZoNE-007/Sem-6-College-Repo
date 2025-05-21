def calculate_power(base, exponent, modulus):
  return pow(base, exponent, modulus)

q=int(input("Enter a prime number 'q': "))
alpha = int(input(f"Enter a primitive root (alpha) of {q}, such that alpha < {q}: "))

Xa = int(input(f"Enter private key of User A (Xa), Xa < {q}: "))
Xb = int(input(f"Enter private key of User B (Xb), Xb < {q}: "))

Ya = calculate_power(alpha, Xa, q)
Yb = calculate_power(alpha, Xb, q)

Ka = calculate_power(Yb, Xa, q)
Kb = calculate_power(Ya, Xb, q)

print("\n--- Diffie-Hellman Key Exchange Results ---")
print("Prime number (q):", q)
print("Primitive root (alpha):", alpha)
print("User A private key (Xa):", Xa)
print("User A public key (Ya):", Ya)
print("User B private key (Xb):", Xb)
print("User B public key (Yb):", Yb)
print("Secret key calculated by A (Ka):", Ka)
print("Secret key calculated by B (Kb):", Kb)
print("Key exchange successful:", Ka == Kb)