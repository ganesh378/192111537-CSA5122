#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate (a^b) % c using the square-and-multiply algorithm
int power(int a, unsigned int b, int c) {
    int result = 1;
    a = a % c;

    while (b > 0) {
        // If b is odd, multiply result with a
        if (b & 1)
            result = (result * a) % c;

        // Square a and reduce it modulo c
        a = (a * a) % c;

        // If b is even, divide it by 2
        if (b % 2 == 0)
            b = b >> 1;
        else
            b--;
    }

    return result;
}

// Function to generate key pairs
void generate_key_pairs(int p, int q, int *e, int *d, int *n) {
    // Calculate n
    *n = p * q;

    // Calculate totient of n
    int totient = (p - 1) * (q - 1);

    // Choose e such that 1 < e < totient and gcd(e, totient) = 1
    *e = 2; // starting with a small prime for simplicity
    while (gcd(*e, totient) != 1) {
        (*e)++;
    }

    // Calculate d such that (d * e) % totient = 1
    *d = 0;
    while (((*d) * (*e) % totient) != 1) {
        (*d)++;
    }
}

// Function to perform RSA encryption
int encrypt(int plaintext, int e, int n) {
    return power(plaintext, e, n);
}

// Function to perform RSA decryption
int decrypt(int ciphertext, int d, int n) {
    return power(ciphertext, d, n);
}

int main() {
    int p, q, e, d, n;
    long long plaintext, ciphertext, decrypted_text;

    // Input prime numbers p and q
    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter prime number q: ");
    scanf("%d", &q);

    // Generate key pairs
    generate_key_pairs(p, q, &e, &d, &n);

    // Input plaintext
    printf("Enter plaintext: ");
    scanf("%lld", &plaintext);

    // Encrypt the plaintext
    ciphertext = encrypt(plaintext, e, n);
    printf("Ciphertext: %lld\n", ciphertext);

    // Decrypt the ciphertext
    decrypted_text = decrypt(ciphertext, d, n);
    printf("Decrypted Text: %lld\n", decrypted_text);

    return 0;
}
