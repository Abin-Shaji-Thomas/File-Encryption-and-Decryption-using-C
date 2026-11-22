# XOR File Transformation Demo (C)

A small menu-driven C program that creates a text file or applies a single-character XOR transformation to an existing file. The source is `encryt_decrypt.c`.

## Important security note

This is an educational XOR demonstration, **not secure encryption**. A single-character XOR key offers no meaningful confidentiality and must not be used to protect real files or sensitive information. Work only with disposable sample files.

## Build and run

With GCC installed:

```sh
gcc encryt_decrypt.c -o encryption_tool
./encryption_tool
```

On Windows, run the resulting `encryption_tool.exe` from Command Prompt or PowerShell. Follow the program's menu prompts. Use the same key for the reverse XOR operation and keep a backup of any sample file.

## Repository contents

- `encryt_decrypt.c` — program source
- `LICENSE` — project license

## Requirements

A C compiler such as GCC or Clang. The program uses standard C facilities.
