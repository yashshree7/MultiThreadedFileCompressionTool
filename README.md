# Multi-Threaded File Compression Tool

## Overview

The Multi-Threaded File Compression Tool is a console-based application developed in C that compresses and decompresses text files using the Run-Length Encoding (RLE) algorithm. It also supports compressing multiple files simultaneously using Windows threads, improving processing efficiency.

This project demonstrates concepts such as file handling, multithreading, synchronization, debugging, and performance measurement.

---

## Features

- Compress text files using Run-Length Encoding (RLE)
- Decompress previously compressed files
- Compress multiple files simultaneously using Windows threads
- Display compression statistics:
  - Original file size
  - Compressed file size
  - Space saved
  - Compression ratio
- Prevent accidental overwriting of compressed files
- Measure and display compression execution time
- Menu-driven console interface

---

## Technologies Used

- C Programming
- Windows Threads (WinAPI)
- File Handling
- Multithreading
- Run-Length Encoding (RLE)
- Visual Studio Code
- GCC (MSYS2/MinGW)

---

## Project Structure

```
MultiThreadedFileCompressionTool/
│
├── include/
│   ├── compression.h
│   └── thread_handler.h
│
├── input/
│   ├── sample.txt
│   ├── college.txt
│   └── notes.txt
│
├── output/
│   ├── compressed_sample.txt
│   ├── compressed_college.txt
│   ├── compressed_notes.txt
│   └── decompressed_compressed_sample.txt.txt
│
├── src/
│   ├── main.c
│   ├── compression.c
│   └── thread_handler.c
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## How to Compile

Open Command Prompt in the project folder and run:

```bash
gcc src/main.c src/compression.c src/thread_handler.c -o Compressor
```

---

## How to Run

```bash
Compressor
```

or

```bash
.\Compressor.exe
```

---

## Menu

```
1. Compress File
2. Decompress File
3. Compress Multiple Files
4. Compression Statistics
5. Exit
```

---

## Sample Input

```
Input File

AAAAABBBBBCCCCCCCCDDDDDDDDDD
```

### Compressed Output

```
A5B5C8D10
```

### Decompressed Output

```
AAAAABBBBBCCCCCCCCDDDDDDDDDD
```

---

## Concepts Demonstrated

- File Handling
- Multithreading
- Thread Synchronization
- Run-Length Encoding (RLE)
- Performance Measurement
- Error Handling
- Console-Based User Interface
- Software Documentation

---

## Future Enhancements

- Support Binary File Compression
- Support ZIP Compression Algorithm
- Add File Selection Using Windows File Dialog
- Display Progress Bar During Compression
- Compress Entire Folders
- Improve Compression Efficiency for Large Files

---

## Author

**Yashshree Shah**

Computer Engineering Graduate (2024)
