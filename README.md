# Text File to C-Array

This program reads file with numbers, each in one line, and converts it into a C array.

For example, if the file called `input.txt` stores

```
0x6a09e667
0xbb67ae85
0x3c6ef372
0xa54ff53a
0x9b05688c
0x1f83d9ab
0x5be0cd19
0x9159015a
0xcf6c85d3
0x6f196331
```

Then after executing program with command
`./<this_program> input.txt output.c int A`,
the file `output.c` will store data as

```c
int A[] = {
	0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19,
	0x9159015a,
	0xcf6c85d3,
	0x6f196331
};
```
