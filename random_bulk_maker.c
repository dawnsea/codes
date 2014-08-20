#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

main(int argc, char *argv[]) {

        int fd;
        int i;
        unsigned int a;
        int size;

        if (argc < 4) printf("filename size(MB)\n");

        size=atoi(argv[2]);

        fd = open(argv[1], O_CREAT | O_RDWR, 0644);


        for (i = 0; i < 1024 * 1024 * size / sizeof(unsigned int); i++) {
                a = (unsigned int)random();
                write(fd, &a, sizeof(unsigned int));
        }
        close(fd);
}

