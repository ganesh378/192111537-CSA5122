#include <stdio.h>
#include <string.h>

#define SIZE 5

void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int k, i, j;
    char keySet[26] = {0};
    int len = strlen(key);

    // Fill the keySet array with unique characters from the key
    k = 0;
    for (i = 0; i < len; i++) {
        if (key[i] != 'j') {
            if (keySet[key[i] - 'a'] == 0) {
                keySet[key[i] - 'a'] = 1;
                keyTable[k / SIZE][k % SIZE] = key[i];
                k++;
            }
        }
    }

    // Fill the remaining characters in keySet
    for (i = 0; i < 26; i++) {
        if (keySet[i] == 0) {
            keySet[i] = 1;
            keyTable[k / SIZE][k % SIZE] = 'a' + i;
            k++;
        }
    }
}

void search(char keyTable[SIZE][SIZE], char a, char b, int arr[]) {
    int i, j;

    if (a == 'j') a = 'i';
    else if (b == 'j') b = 'i';

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            } else if (keyTable[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(char keyTable[SIZE][SIZE], char plaintext[]) {
    int i, a[4];

    for (i = 0; i < strlen(plaintext); i += 2) {
        search(keyTable, plaintext[i], plaintext[i + 1], a);
        if (a[0] == a[2]) {
            printf("%c%c ", keyTable[a[0]][(a[1] + 1) % SIZE], keyTable[a[2]][(a[3] + 1) % SIZE]);
        } else if (a[1] == a[3]) {
            printf("%c%c ", keyTable[(a[0] + 1) % SIZE][a[1]], keyTable[(a[2] + 1) % SIZE][a[3]]);
        } else {
            printf("%c%c %c%c ", keyTable[a[0]][a[3]], keyTable[a[1]][a[2]], keyTable[a[2]][a[1]], keyTable[a[3]][a[0]]);
        }
    }
}

int main() {
    char key[SIZE * SIZE], plaintext[100];
    char keyTable[SIZE][SIZE];

    printf("Enter the key: ");
    scanf("%s", key);

    generateKeyTable(key, keyTable);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Encrypted text: ");
    encrypt(keyTable, plaintext);

    return 0;
}

