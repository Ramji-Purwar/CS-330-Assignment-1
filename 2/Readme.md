**2. Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?**

Both parent and child process try to write in same file, but both write operation are not called at same time.

Thet are called by kernal one after another, the order might not be same always.