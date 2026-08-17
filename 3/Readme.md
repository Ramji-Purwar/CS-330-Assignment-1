**3. Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?**

We can use `sleep()` for parent process. this will delay prarent. But this method doesn;t guarentee that child process will be executed first.