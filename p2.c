#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int i,j;
	printf("--Start of Lab 2 program--\n");
    pid_t pid = fork();

            if (pid < 0)
            {
                perror("Fork failed");
            }
            if (pid == 0)
            {
                for (i = 1; i < argc; i++)
                {
                    pid_t pid = fork();
                    if(pid == 0)
                    {
                        wait(2);
                        printf("Filename:%s          PID: %d\n",argv[i],getpid());
                        exit(0);
                    }

                }

            }
            if (pid > 0)
            {
                printf("Filename:%s          PID: %d\n",argv[0],getpid());
                wait(NULL);
                system("ps -H");
            }
}
