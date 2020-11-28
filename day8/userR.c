#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("/dev/sample0",O_RDWR);
    if(fd<0)
    {
        perror("ERROR OPENING");
        return fd;
    }
    return 0;
}