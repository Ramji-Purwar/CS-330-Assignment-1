/*
8. Write a program that creates two children, and connects the standard
output of one to the standard input of the other, using pipe().
*/

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        cout << "Pipe failed" << endl;
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        cout << "Fork 1 failed" << endl;
        return 1;
    }

    if (pid1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execl("/bin/ls", "ls", NULL);
        cout << "execl ls failed" << endl;
        return 1;
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        cout << "Fork 2 failed" << endl;
        return 1;
    }

    if (pid2 == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        execl("/usr/bin/wc", "wc", NULL);
        cout << "execl wc failed" << endl;
        return 1;
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}