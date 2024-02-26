#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"

int main() {
    unsigned char data[] = "This is the data to be signed";
    unsigned char *signature;
    int siglen;

    RSA_KEY key;
    RSA_priv_key_new(&key, 1024);

    signature = malloc(RSA_size(&key));
    if (!signature) {
        fprintf(stderr, "Error allocating memory for signature\n");
        return 1;
    }

    siglen = RSA_sign(&key, data, sizeof(data) - 1, signature);
    if (siglen <= 0) {
        fprintf(stderr, "Error creating signature\n");
        return 1;
    }

    printf("Signature: ");
    for (int i = 0; i < siglen; i++) {
        printf("%02X", signature[i]);
    }
    printf("\n");

    RSA_free(&key);
    free(signature);

    return 0;
}
