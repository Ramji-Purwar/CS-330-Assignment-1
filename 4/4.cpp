/*
4. Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?
*/

#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    }
    else if(pid == 0) {
        cout << "Child process executing /bin/ls using execl()" << endl;
        execl("/bin/ls", "ls", NULL);
        cout << "execl() failed" << endl;
        return 1;
    }
    else {
        wait(NULL);
        cout << "Parent process completed" << endl;
    }
}