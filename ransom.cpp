#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Function to "encrypt" (rename) files
void encryptFiles(const std::string& directory) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.path().extension() == ".txt") {  // Targeting text files
            fs::rename(entry.path(), entry.path().parent_path() / ("ENCRYPTED_" + entry.path().filename().string()));
        }
    }
    std::cout << "Files have been 'encrypted'." << std::endl;
}

// Function to "decrypt" (rename back) files
void decryptFiles(const std::string& directory, const std::string& key) {
    if (key == "correct_key") {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.path().filename().string().find("ENCRYPTED_") == 0) {
                fs::rename(entry.path(), entry.path().parent_path() / entry.path().filename().string().substr(10));
            }
        }
        std::cout << "Files have been 'decrypted'." << std::endl;
    } else {
        std::cout << "Incorrect key. Files remain 'encrypted'." << std::endl;
    }
}

int main() {
    std::string targetDir = "/path/to/target/directory";

    // Simulate the attack
    encryptFiles(targetDir);

    // Simulate the decryption with the correct key
    std::string decryptKey;
    std::cout << "Enter decryption key: ";
    std::cin >> decryptKey;
    decryptFiles(targetDir, decryptKey);

    return 0;
}