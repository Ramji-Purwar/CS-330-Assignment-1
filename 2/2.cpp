/*
2. Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(file < 0) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    pid_t pid = fork();
    if(pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    } 
    else if(pid == 0) {
        string childMsg = "Child modifying the file\n";
        if(write(file, childMsg.c_str(), childMsg.size()) < 0) {
            cout << "Child write failed" << endl;
        }
    }
    else {
        string parentMsg = "Parent modifying the file\n";
        if(write(file, parentMsg.c_str(), parentMsg.size()) < 0) {
            cout << "Parent write failed" << endl;
        }
    }

    if (close(file) < 0) {
        cerr << "Failed to close file descriptor" << endl;
        return 1;
    }

    return 0;
}