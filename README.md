# Bitwise encrypting program

The current project is Two-way encrypting program, which uses bitwise operations in C to swap every two bits
in every byte of given file.

For example if you have the current byte:
> **0 1   0 0   1 0   1 1**


The program will swap the bits as follows:
> **0 <-> 1 | 0 <-> 0 | 1 <-> 0 | 1 <-> 1**


And the result is:
> **1 0  0 0  0 1  1 1**
