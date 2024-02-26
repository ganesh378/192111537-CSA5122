#include <stdio.h>
#include <math.h>

// Function to calculate (base ^ exponent) % modulus
long long int power(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

// Function to perform the Diffie-Hellman key exchange
long long int diffieHellman(long long int base, long long int private_key, long long int prime) {
    return power(base, private_key, prime);
}

int main() {
    // Shared prime and base (publicly known)
    long long int prime = 23;  // A small prime for simplicity
    long long int base = 5;    // A primitive root modulo prime

    // Alice's private key
    long long int alice_private_key = 6;  // Should be kept secret

    // Bob's private key
    long long int bob_private_key = 15;   // Should be kept secret

    // Calculate public keys for Alice and Bob
    long long int alice_public_key = diffieHellman(base, alice_private_key, prime);
    long long int bob_public_key = diffieHellman(base, bob_private_key, prime);

    // Calculate the shared secret
    long long int shared_secret_alice = diffieHellman(bob_public_key, alice_private_key, prime);
    long long int shared_secret_bob = diffieHellman(alice_public_key, bob_private_key, prime);

    // Display the results
    printf("Prime: %lld, Base: %lld\n", prime, base);
    printf("Alice's Public Key: %lld\n", alice_public_key);
    printf("Bob's Public Key: %lld\n", bob_public_key);
    printf("Shared Secret (Alice): %lld\n", shared_secret_alice);
    printf("Shared Secret (Bob): %lld\n", shared_secret_bob);

    return 0;
}

