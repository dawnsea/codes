#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char log_msg[1024];

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_un serveraddr;
    int clilen;
    int count = 0;

    sockfd = socket(AF_LOCAL, SOCK_DGRAM, 0); 
    if (sockfd < 0)
    {
        perror("exit : ");
        exit(0);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sun_family = AF_LOCAL;
    strcpy(serveraddr.sun_path, argv[1]);
  
  
    while(1) {
        
        sprintf(log_msg, "dflsjdklfjsdksd %d", count++);

		if (sendto(sockfd, (void *)&log_msg, strlen(log_msg), 0, 
					(struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
		{
			perror("send error : ");
			exit(0);
		}

	}

    close(sockfd);
    exit(0);
}
			
