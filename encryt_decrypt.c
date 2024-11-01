#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the file
void encryptDecrypt(const char *fileName, char key) {
    FILE *file = fopen(fileName, "rb+"); // Open file for reading and writing
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("File opened successfully.\n"); // Confirm file opened

    // First, find out the length of the file
    fseek(file, 0, SEEK_END); // Move to the end of the file
    long fileSize = ftell(file); // Get the current position (file size)
    fseek(file, 0, SEEK_SET); // Move back to the start of the file

    // Create a buffer to hold the file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, fileSize, file);
    
    // Encrypt/Decrypt the contents
    for (long i = 0; i < fileSize; i++) {
        printf("Original character: %c\n", buffer[i]); // Debugging line
        buffer[i] = buffer[i] ^ key; // XOR with key
        printf("Encrypted/Decrypted character: %c\n", buffer[i]); // Debugging line
    }

    // Write the modified contents back to the file
    fseek(file, 0, SEEK_SET); // Go back to the start of the file
    fwrite(buffer, 1, fileSize, file); // Write the buffer back to the file

    // Clean up
    free(buffer);
    fclose(file);
    printf("Operation successful.\n");
}

void createFile(const char *fileName) {
    FILE *file = fopen(fileName, "w"); // Create a new file for writing
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return;
    }

    printf("Enter content for the file (type 'exit' on a new line to save and finish):\n");
    
    // Get user input to write to the file
    char buffer[256];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin); // Read a line of input
        if (strcmp(buffer, "exit\n") == 0) { // Check if user typed "exit"
            break; // Exit the loop if "exit" is entered
        }
        fputs(buffer, file); // Write the input to the file
    }

    fclose(file);
    printf("File created successfully.\n");
}

int main() {
    char fileName[100];
    char key;
    int choice;

    printf("File Encryption/Decryption Tool\n");
    printf("1. Create a new file\n");
    printf("2. Encrypt/Decrypt an existing file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character left by scanf

    if (choice == 1) {
        printf("Enter a name for the new file (including the extension, e.g., 'myfile.txt'): ");
        scanf("%s", fileName);
        getchar(); // Consume the newline character
        createFile(fileName); // Call function to create a new file
        
        // Ask if the user wants to encrypt or decrypt the newly created file
        printf("Do you want to encrypt or decrypt this file? (e for encrypt, d for decrypt): ");
        char operation;
        scanf(" %c", &operation);
        getchar(); // Consume the newline character

        if (operation == 'e' || operation == 'E') {
            printf("Enter a single character key for encryption: ");
            scanf(" %c", &key);
            encryptDecrypt(fileName, key); // Call function to perform encryption
        } else if (operation == 'd' || operation == 'D') {
            printf("Enter a single character key for decryption: ");
            scanf(" %c", &key);
            encryptDecrypt(fileName, key); // Call function to perform decryption
        } else {
            printf("Invalid operation. Exiting.\n");
        }
    } else if (choice == 2) {
        printf("Enter file name to encrypt/decrypt: ");
        scanf("%s", fileName);
        printf("Enter a single character key for encryption/decryption: ");
        scanf(" %c", &key);
        encryptDecrypt(fileName, key); // Call function to perform encryption/decryption
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    return 0;
}
