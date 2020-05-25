#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_LEN 256
#define DELAY_TIME 1

int main(int argc, char *argv[]) 
{      
  	char * a = argv [ 1 ];
    int n = Chanl (a);
    pid_t pid;
    int pipe_fd[2];
    char buf[MAX_DATA_LEN];
    const char data[] = "pipe test";
    int real_read, real_write;

    memset((void *)buf, 0, sizeof(buf));

    / *Create a pipeline * /
        if (pipe(pipe_fd) < 0)
    {
        printf("pipe create error\n");
        exit(1);
    }

    if ((pid = fork()) == 0)
    {
        close(pipe_fd[1]);
        / *Child process close write descriptor * /
            sleep(DELAY_TIME * 3);
        if ((real_read = read(pipe_fd[0], buf, MAX_DATA_LEN)) > 0)
        {
            printf("%d bytes read from the pipe is '%s'\n", real_read, buf);
        }
        close(pipe_fd[0]);
        float S;
        read(p[0], &n, 100);
        int sig = 1;
        for (int i = 0; i < n; ++i)
        {
            S = S + sig / (2.0 * i + 1.0);
            sig = sig * -1;
        }
        printf("%lf\n", 4 * S);

        exit(0);
    }
    else if (pid > 0)
    {
        / *Close parent process read descriptor * /
            close(pipe_fd[0]);
        sleep(DELAY_TIME);

        if ((real_write = write(pipe_fd[1], data, strlen(data))) != -1)
        {
            printf("parent wrote %d bytes:'%s'\n", real_write, data);
        }

        close(pipe_fd[1]);

        waitpid(pid, NULL, 0);
        exit(0);
    }
}