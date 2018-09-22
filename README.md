a simple interpreter
====================
A simple interpreter according to the book [The Unix Programming Enviornment](https://www.amazon.com/Unix-Programming-Environment-Prentice-Hall-Software-dp-0139376992/dp/0139376992/ref=mt_hardcover?_encoding=UTF8) Chapter 8. The authors of the book are Brian W. Kernighan and Rob Pike.

There are only some small modifications on the original code to make it compilable under the current Linux gcc.

To run the codes under Linux,
```
bison hoc.y
gcc hoc.tab.c -o hoc1
./hoc1
```

