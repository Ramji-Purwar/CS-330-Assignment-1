**1. Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?**

Before `fork()` : x = 100

When we fork(), all the variable got copies into child process also. So both child and parent have their own x = 100
