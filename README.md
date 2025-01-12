# Password Cracker

This project is a simple C++ program that demonstrates a brute-force password-cracking algorithm. It takes an input password, predicts the time required to crack it based on the number of possible combinations, and then measures the actual time taken to find the password.

---

## Features

- **Password Input**: User provides the password to be cracked.
- **Charset Support**: Supports lowercase, uppercase letters, and digits.
- **Time Prediction**: Estimates the time required to crack the password based on brute force.
- **Actual Time Measurement**: Uses the C++ `chrono` library to measure the actual time taken.
- **Dynamic Charset Expansion**: Automatically increases the search space for longer passwords.

---

## Requirements

- A C++ compiler supporting C++11 or later (e.g., GCC, Clang, MSVC).
- Basic understanding of compiling and running C++ programs.

---

## Usage

1. Clone or download the project source code.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o password_cracker password_cracker.cpp
   ```
3. Run the program:
   ```bash
   ./password_cracker
   ```
4. Enter the password you want the program to crack.

---

## How It Works

1. **Password Input**: The program asks the user to input a password.
2. **Charset Initialization**: The program uses a predefined charset (`abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`) for brute force.
3. **Prediction**: The total number of combinations and the estimated cracking time are calculated.
4. **Brute Force**: The program generates and checks all possible combinations of characters until the password is found.
5. **Timing**: Measures the time taken from the start of the brute force to the discovery of the password.

---

## Example Output

```plaintext
Enter the password to crack: abc
Estimated time to crack: 2.48 seconds
Password cracked! It was: abc
Actual time taken: 2.452 seconds
```

---

## Notes

- **Efficiency**: This program is for educational purposes and demonstrates the computational complexity of brute force. It's not optimized for real-world use.
- **Exponential Growth**: As password length increases, the time to crack it grows exponentially due to the nature of brute force.
- **Charset Expansion**: The program currently uses a fixed charset, but it can be modified to include special characters.

---

## Disclaimer

This project is designed for educational purposes only. Do not use it for malicious activities or unauthorized password cracking. Always respect privacy and legal guidelines.

---

Enjoy exploring the world of brute force algorithms with this simple password cracker!

