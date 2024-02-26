#include <stdio.h>
#include <ctype.h>

// Function to perform monoalphabetic substitution encryption
void encryptMonoalphabetic(char plaintext[], char mapping[]) {
    printf("Encrypted text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char encrypted;
            if (islower(plaintext[i])) {
                encrypted = mapping[plaintext[i] - 'a'];
            } else {
                encrypted = mapping[plaintext[i] - 'A'];
            }
            printf("%c", encrypted);
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

// Function to perform monoalphabetic substitution decryption
void decryptMonoalphabetic(char ciphertext[], char mapping[]) {
    printf("Decrypted text: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char decrypted;
            if (islower(ciphertext[i])) {
                for (int j = 0; j < 26; j++) {
                    if (mapping[j] == ciphertext[i]) {
                        decrypted = 'a' + j;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    if (mapping[j] == ciphertext[i]) {
                        decrypted = 'A' + j;
                        break;
                    }
                }
            }
            printf("%c", decrypted);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

int main() {
    char mapping[26];
    char plaintext[100];

    // Get user-defined mapping
    printf("Enter the mapping for each letter of the plaintext alphabet (case-insensitive):\n");
    printf("For example, if 'a' should be mapped to 'x', enter 'x' for 'a': ");
    
    for (int i = 0; i < 26; i++) {
        scanf(" %c", &mapping[i]);
        if (!isalpha(mapping[i])) {
            printf("Invalid input. Please enter a valid letter.\n");
            return 1;
        }
    }

    // Encryption
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);
    encryptMonoalphabetic(plaintext, mapping);

    // Decryption
    printf("Enter the ciphertext: ");
    scanf(" %[^\n]s", plaintext);
    decryptMonoalphabetic(plaintext, mapping);

    return 0;
}

