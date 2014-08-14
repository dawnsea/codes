#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int main()
{
        FILE *fp;
        unsigned int count = 0;
        char my_filename[20];
        unsigned int my_bufferh;
        unsigned int my_bufferl;
        int ret;

        printf("fs aging!\n");

        while (1) {

                sprintf(my_filename, "%d", count % 3000);

                printf("- %s\r", my_filename);

                fp = fopen(my_filename, "w");

                if (!fp) {
                        printf("open error! %d, %s\n", count, strerror(errno));
                        return 0;
                }

                switch (count % 4) {
                        case 0: my_bufferh = 0xaaaaaaaa; break;
                        case 1: my_bufferh = 0x55555555; break;
                        case 2: my_bufferh = rand(); break;
                        case 3: my_bufferh = 0xffffffff; break;
                }</div>
<div>                ret = fwrite(&my_bufferh, 1, 4, fp);
                if (ret != 4) {
                        printf("write error! %d, %s\n", count, strerror(errno));
                        return 0;
                }

                ret = fwrite(&my_bufferh, 1, 4, fp);
                if (ret != 4) {
                        printf("write error! %d, %s\n", count, strerror(errno));
                        return 0;
                }

                fclose(fp);

                fp = fopen(my_filename, "r");

                if (!fp) {
                        printf("open error! %d, %s\n", count, strerror(errno));
                        return 0;
                }

                my_bufferl = 0;

                ret = fread(&my_bufferl, 1, 4, fp);
                if (ret != 4 || my_bufferl != my_bufferh) {
                        printf("read error! %d, %s\n", count, strerror(errno));
                        return 0;
                }
                my_bufferl = 0;

                ret = fread(&my_bufferl, 1, 4, fp);
                if (ret != 4 || my_bufferl != my_bufferh) {
                        printf("write error! %d, %s\n", count, strerror(errno));
                        return 0;
                }
//              printf("%x\n", my_bufferl);
                fclose(fp);
                count++;
        }

        return 0;
}

