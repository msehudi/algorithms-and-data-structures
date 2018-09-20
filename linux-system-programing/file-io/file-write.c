#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void main()
{
    int fd = open("hello.txt", O_WRONLY, O_CREAT);
    const char *buf = "Hello Systems Programing.\nHere I come.\n";
    ssize_t nr;
    if (fd != -1)
    {
        nr = write(fd, buf, strlen(buf));
        if (nr == -1)
        {
            perror("error writing to file");
            printf("\n");
        }
        close(fd);
    }
    else
    {
        perror("error opening file");
        printf("\n");
    }
}