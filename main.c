#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/_types/_pid_t.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_BUF_LEN 1024
#define MAX_ARGS 64

int main() {
    while(1) {
        char buf[MAX_BUF_LEN];
        printf("mysh$ ");
        fflush(stdout);
        // get command into buffer
        if (!fgets(buf,MAX_BUF_LEN,stdin)) break;
        buf[strcspn(buf, "\n")] = 0;
        char* args[MAX_ARGS];

        int i=0;
        char* cur_token = strtok(buf, " ");
        char* command = cur_token;
        while(cur_token != NULL) {
            cur_token = strtok(NULL, " ");
            args[i++] = cur_token;
        }
        args[i] = NULL;
        
        if (command != NULL) {
            pid_t pid = fork();
            if(pid == 0) {
                // child process
                execvp(command, args);
                printf("Child process failed\n");
            } else if(pid == -1){
                printf("Failed to create a fork process\n");
            } else {
                wait(NULL);
            }
        }
    }
    printf("mysh$ QUIT\n");
    return 0;
}
