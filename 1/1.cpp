/*
1. Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change the value of x?
*/

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    int x = 100;
    cout << "Before fork, x = " << x << endl;

    pid_t pid = fork();
    if(pid < 0) {
        cout << "Forked Failed" << endl;
        return 1;
    }
    else if(pid == 0) {
        cout << "Child process: x = " << x << endl;
        x = 200;
        cout << "Child process after changing x: x = " << x << endl;
    }
    else {
        cout << "Parent process: x = " << x  << endl;
        x = 300;
        cout << "Parent process after changing x: x = " << x << endl;
    }
}