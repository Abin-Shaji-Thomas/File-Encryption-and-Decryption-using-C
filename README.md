
# File Encryption and Decryption Tool

This project is a basic C-based file encryption and decryption tool. It allows users to secure their files by encrypting or decrypting content with a single-character XOR key. The tool can either create a new file from user input or process an existing file.

## Features

- **File Creation**: Option to create a new file and add content directly.
- **Encryption and Decryption**: Uses XOR-based encryption, requiring a single-character key to perform both encryption and decryption.
- **Text or Binary File Support**: Works with any file type.
- **Simple Interface**: Menu-driven with easy-to-follow prompts.

## How It Works

The program uses a bitwise XOR operation to encrypt or decrypt each character in the file using a key provided by the user. XOR-based encryption is lightweight and suitable for simple security needs.

### Example

1. Choose to create a new file or work with an existing one.
2. If creating a new file, enter the file content line by line.
3. Enter a single-character key to encrypt or decrypt the content.
4. The tool processes the file, replacing each character with an XOR result of the character and key.

## Usage Instructions

1. **Compilation**: Compile the code with a C compiler, such as GCC.
   ```bash
   gcc encryption_tool.c -o encryption_tool
   ```

2. **Running the Tool**:
   ```bash
   ./encryption_tool
   ```

3. **Menu Options**:
   - Choose `1` to create a new file and input content.
   - Choose `2` to encrypt or decrypt an existing file.

4. **Enter Key**: Input a single character to act as the encryption/decryption key. **Note**: Use the same key for both encryption and decryption.

### Sample Output
```
File Encryption/Decryption Tool
1. Create a new file
2. Encrypt/Decrypt an existing file
Enter your choice (1 or 2):
```

## Requirements

- C compiler (e.g., GCC)
- Text editor to edit and compile C code

## Future Enhancements

- Add support for multiple encryption algorithms
- Option to enter a multi-character key for added security
- User interface improvements for easier navigation

---
