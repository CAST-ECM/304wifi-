#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
#define PORT 60000
#define MAXDATASIZE 256
int main()
{
    int socket_fd;
    struct sockaddr_in my_addr,user_addr;
    char buf1[MAXDATASIZE]={0x7e,0xa6,0xe0,0x82,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x02,0x0d};
   // 7ea6 e0 01 11 01 0000000000000000000000000000000000000000000000000099010d
    char buf2[MAXDATASIZE]={0x7e,0xa6,0xe0,0x01,0x11,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x99,0x01,0x0d};
    //7e a6 e0 9d 10 01 01 00000000000000000000000000000000000000000000000035020d
    char buf3[MAXDATASIZE]={0x7e,0xa6,0xe0,0x9d,0x10,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x35,0x02,0x0d};
   // 7e a6 e0 8c 10 000000000000000000000000000000000000000000000000000022020d
    char buf4[MAXDATASIZE]={0x7e,0xa6,0xe0,0x8c,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x02,0x0d};
   // 7e a6 e0 81 10 04 000000000000000000000000000000000000000000000000001b020d
    char buf5[MAXDATASIZE]={0x7e,0xa6,0xe0,0x81,0x10,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x02,0x0d};
    // 7e a6 e0 f1 10 1a 00000000000000000000000000000000000000000000000000a1020d
    char buf6[MAXDATASIZE]={0x7e,0xa6,0xe0,0xf1,0x10,0x1a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa1,0x02,0x0d};
   // 7e a6 e0 f1 10 12 0000000000000000000000000000000000000000000000000099020d
    char buf7[MAXDATASIZE]={0x7e,0xa6,0xe0,0xf1,0x10,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x99,0x02,0x0d};

    int so_broadcast=1;
    //socklen_t size;
    char my_ip[12];
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(60000);
    my_addr.sin_addr.s_addr=inet_addr("255.255.255.255");
    bzero(&(my_addr.sin_zero),8);
    
    user_addr.sin_family=AF_INET;
    user_addr.sin_port=htons(60000);
    user_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    bzero(&(user_addr.sin_zero),8);
    socket_fd=(socket(AF_INET,SOCK_DGRAM,0));
    // if((socket_fd=(socket(AF_INET,SOCK_DGRAM,0)))==-1) {
    //     perror("socket");
    //     exit(1);
    // }
    setsockopt(socket_fd,SOL_SOCKET,SO_BROADCAST,&so_broadcast,sizeof(so_broadcast));
    bind(socket_fd,(struct sockaddr *)&user_addr, sizeof(struct sockaddr));
    // if((bind(socket_fd,(struct sockaddr *)&user_addr,
    //                     sizeof(struct sockaddr)))==-1) {
    //     perror("bind");
    //     exit(1);
    // }
  
    sendto(socket_fd,buf1,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
    //strcpy(buf,"7ea6e00111010000000000000000000000000000000000000000000000000099010d");
    sendto(socket_fd,buf2,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   // strcpy(buf,"7ea6e09d10010100000000000000000000000000000000000000000000000035020d");
    sendto(socket_fd,buf3,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   // strcpy(buf,"7ea6e08c10000000000000000000000000000000000000000000000000000022020d");
    sendto(socket_fd,buf4,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   // strcpy(buf,"7ea6e0811004000000000000000000000000000000000000000000000000001b020d");
    sendto(socket_fd,buf5,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   // strcpy(buf,"7ea6e0f1101a00000000000000000000000000000000000000000000000000a1020d");
    sendto(socket_fd,buf6,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   // strcpy(buf,"7ea6e0f110120000000000000000000000000000000000000000000000000099020d");
    sendto(socket_fd,buf7,34,0,(struct sockaddr *)&my_addr,sizeof(my_addr));
   
    return 0;
}