🔐 RSA Encryption/Decryption in C
This project allows you to encrypt and decrypt messages using the RSA algorithm written in C.

📁 Files
RSA.c — Main program for encryption and decryption.

modexp.c — Contains modular exponentiation logic.

modinverse.c — Contains modular inverse function.

gcd.c — Contains gcd function.

Public.txt — Used to store the input message, encrypted data, or decrypted output.

🧾 How to Use
Prepare the Message

Edit Public.txt and write the message you want to encrypt (e.g., Hello).

Save and close the file.

Compile the Program
Run this command in the terminal:


1."gcc RSA.c modexp.c modinverse.c gcd. -o rsa"

2."./rsa"


Enter two large prime numbers (e.g., 61 and 53).

Choose:

1 for encryption

2 for decryption

Enter the correct public/private key when asked.

The encrypted or decrypted result will be saved in Public.txt.

📌 Notes
For encryption, you’ll be asked to enter the public key e.

For decryption, you’ll need the private key d.

Encrypted output is saved as space-separated integers.

Decryption will restore the original text in Public.txt.

Let me know if you'd like the README to be styled for GitHub or have additional sections like license, contributors, or example input/output.