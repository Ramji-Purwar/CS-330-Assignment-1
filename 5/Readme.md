**5. Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?**

- In the parent : `wait()` blocks until the child finished then returns the child's PID.
- In the child : `wait()` is usually invalid because it doesn't have its own child, so here it return -1.