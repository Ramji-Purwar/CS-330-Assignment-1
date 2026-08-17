/*
7. Write a program that creates a child process, and then in the child
closes standard output (STDOUT_FILENO). What happens if the child
calls printf() to print some output after closing the descriptor? 
*/

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid < 0) {
        cout << "Forked failed" << endl;
        return 1;
    }
    else if(pid == 0) {
        close(STDOUT_FILENO);
        cout << "Child process" << endl;
    }
    else {
        cout << "Parent process" << endl;
    }
}