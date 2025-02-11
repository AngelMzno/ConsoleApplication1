#include <stdio.h>
#include <sodium.h>

int main(void) {
    // Initialize the Libsodium library
    if (sodium_init() < 0) {
        fprintf(stderr, "Error initializing Libsodium\n");
        return -1;
    }

    // Generate a simple random number
    uint32_t random_value = randombytes_random();
    printf("Random value: %u\n", random_value);

    // Generate a uniformly random number within a range
    uint32_t upper_bound = 100;
    uint32_t random_uniform = randombytes_uniform(upper_bound);
    printf("Random uniform value (0 to %u): %u\n", upper_bound - 1, random_uniform);

    // Generate a buffer of random bytes
    unsigned char buffer[32];
    randombytes_buf(buffer, sizeof(buffer));
    printf("Random bytes: ");
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%02x", buffer[i]); // Print in hexadecimal format
    }
    printf("\n");

    return 0;
}