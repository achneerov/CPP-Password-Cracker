#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>

// Function to generate the next password
std::string generateNextPassword(const std::string& current, const std::string& charset) {
    std::string next = current;
    int i = next.size() - 1;

    while (i >= 0) {
        auto pos = charset.find(next[i]);
        if (pos != std::string::npos && pos + 1 < charset.size()) {
            next[i] = charset[pos + 1];
            return next;
        } else {
            next[i] = charset[0];
            i--;
        }
    }
    return std::string(current.size() + 1, charset[0]); // Increase length
}

// Function to estimate time
double estimateTime(const std::string& password, const std::string& charset) {
    double combinations = 0;
    for (int length = 1; length <= password.size(); ++length) {
        combinations += pow(charset.size(), length);
    }
    return combinations / (1e6); // Assuming 1M tries per second
}

int main() {
    std::string password;
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::cout << "Enter the password to crack: ";
    std::cin >> password;

    // Estimate time
    double estimatedTime = estimateTime(password, charset);
    std::cout << "Estimated time to crack: " << estimatedTime << " seconds\n";

    // Start brute force
    std::string guess = std::string(1, charset[0]);
    auto start = std::chrono::high_resolution_clock::now();

    while (guess != password) {
        guess = generateNextPassword(guess, charset);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Password cracked! It was: " << guess << "\n";
    std::cout << "Actual time taken: " << elapsed.count() << " seconds\n";

    return 0;
}
