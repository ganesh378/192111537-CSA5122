#include <stdio.h>
#include <stdint.h>

// Initial and final permutations tables
static const int initial_permutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                                          60, 52, 44, 36, 28, 20, 12, 4,
                                          62, 54, 46, 38, 30, 22, 14, 6,
                                          64, 56, 48, 40, 32, 24, 16, 8,
                                          57, 49, 41, 33, 25, 17, 9, 1,
                                          59, 51, 43, 35, 27, 19, 11, 3,
                                          61, 53, 45, 37, 29, 21, 13, 5,
                                          63, 55, 47, 39, 31, 23, 15, 7};

static const int final_permutation[] = {40, 8, 48, 16, 56, 24, 64, 32,
                                        39, 7, 47, 15, 55, 23, 63, 31,
                                        38, 6, 46, 14, 54, 22, 62, 30,
                                        37, 5, 45, 13, 53, 21, 61, 29,
                                        36, 4, 44, 12, 52, 20, 60, 28,
                                        35, 3, 43, 11, 51, 19, 59, 27,
                                        34, 2, 42, 10, 50, 18, 58, 26,
                                        33, 1, 41, 9, 49, 17, 57, 25};

// Initial permutation of the key
static const int key_permutation[] = {57, 49, 41, 33, 25, 17, 9,
                                      1, 58, 50, 42, 34, 26, 18,
                                      10, 2, 59, 51, 43, 35, 27,
                                      19, 11, 3, 60, 52, 44, 36,
                                      63, 55, 47, 39, 31, 23, 15,
                                      7, 62, 54, 46, 38, 30, 22,
                                      14, 6, 61, 53, 45, 37, 29,
                                      21, 13, 5, 28, 20, 12, 4};

// Key schedule
static const int key_schedule_rotations[] = {1, 1, 2, 2, 2, 2, 2, 2,
                                             1, 2, 2, 2, 2, 2, 2, 1};

// Function to perform the initial permutation
void initialPermutation(uint64_t *data) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((*data >> (64 - initial_permutation[i])) & 1) << (63 - i);
    }
    *data = result;
}

// Function to perform the final permutation
void finalPermutation(uint64_t *data) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((*data >> (64 - final_permutation[i])) & 1) << (63 - i);
    }
    *data = result;
}

// Function to perform the key permutation
void permuteKey(uint64_t *key) {
    uint64_t result = 0;
    for (int i = 0; i < 56; i++) {
        result |= ((*key >> (64 - key_permutation[i])) & 1) << (55 - i);
    }
    *key = result;
}

// Function to generate subkeys
void generateSubkeys(uint64_t key, uint64_t subkeys[16]) {
    permuteKey(&key);

    uint32_t left = (uint32_t)(key >> 28);
    uint32_t right = (uint32_t)key;

    for (int i = 0; i < 16; i++) {
        left = ((left << key_schedule_rotations[i]) | (left >> (28 - key_schedule_rotations[i]))) & 0x0FFFFFFF;
        right = ((right << key_schedule_rotations[i]) | (right >> (28 - key_schedule_rotations[i]))) & 0x0FFFFFFF;

        uint64_t combined = ((uint64_t)left << 28) | right;
        subkeys[i] = combined;
    }
}

// Example usage
int main() {
    // Example 64-bit key (8 bytes)
    uint64_t key = 0x133457799BBCDFF1;

    // Example 64-bit data block (8 bytes)
    uint64_t data = 0x0123456789ABCDEF;

    // Initial permutation of the key
    initialPermutation(&key);

    // Generate subkeys
    uint64_t subkeys[16];
    generateSubkeys(key, subkeys);

    // Encryption rounds go here...

    // Final permutation of the data
    finalPermutation(&data);

    // Display the result
    printf("Encrypted data: 0x%016lx\n", data);

    return 0;
}

