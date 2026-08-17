/*
3. Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?
*/

#include  <bits/stdc++.h>
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
        cout << "Hello" << endl;
    }
    else {
        wait(NULL);
        cout << "Goodbye" << endl;
    }
    return 0;
}