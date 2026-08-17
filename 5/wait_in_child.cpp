/*
5. Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?  
*/

#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid < 0) {
        cout << "Forked failed" << endl;
        return 1;
    }
    else if(pid == 0) {
        wait(NULL);
        cout << "Child process" << endl;
    }
    else {
        cout << "Parent process" << endl;
    }
}