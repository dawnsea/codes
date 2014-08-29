#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char log_msg[1024]; // 최대 1킬로 문장의 로그
    
int main(int argc, char **argv)
{
    int sockfd;

    struct sockaddr_un serveraddr;

    sockfd = socket(AF_LOCAL, SOCK_DGRAM, 0); 
    if (sockfd < 0)
    {
        perror("socket error : ");
        exit(0);
    }    
    unlink(argv[1]);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sun_family = AF_UNIX;
    strcpy(serveraddr.sun_path, argv[1]);

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("bind error : ");
        exit(0);
    }

	int ret;
	int result;

    while(1)
    {
		ret = read(sockfd, (void *)&log_msg, sizeof(log_msg));

//		ret = read(sockfd, (void *)&data_size, sizeof(int));
//        ret = recvfrom(sockfd, (void *)&log_msg, sizeof(log_msg), 0, (struct sockaddr *)&clientaddr, &clilen); 

        if (ret <= 0) continue;
        
        printf("msg = %s\n", log_msg);

    }
    close(sockfd);
    exit(0);
}
