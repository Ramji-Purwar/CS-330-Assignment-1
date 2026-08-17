/*
6. Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?
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
        cout << "Child process" << endl;
    }
    else {
        waitpid(pid, NULL, 0);
        cout << "Parent process" << endl;
    }
}