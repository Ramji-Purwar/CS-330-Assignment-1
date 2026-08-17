**7. Write a program that creates a child process, and then in the child closes standard output (STDOUT_FILENO). What happens if the child calls printf() to print some output after closing the descriptor?**

When child process calls `close(STDOUT_FILENO);`, it closes closes standard output stream for child process.

That's why when `cout << "Child process" << endl;` is called, we don't get any output.

Imp : parent is unaffected.