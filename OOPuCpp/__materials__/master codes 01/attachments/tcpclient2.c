/*TCP client echo */
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#define MAXLINE 200
void str_cli(FILE *fp, int fd)
{
        int n;
        char buffer[MAXLINE];
        while(fgets(buffer, MAXLINE, fp) !=NULL)
        {
                int nw = write(fd, buffer, strlen(buffer));
                if(nw ==-1)
                    perror("write: ");
                n = read(fd,  buffer, MAXLINE);
                if(n ==0)
                {
                    printf("Connection ended ...\n");
                    break;
                }
                if(n<0)
                {
                    printf("Read filed .... \n");
                }
                buffer[n]='\0';
                printf("data recieved from server : %s\n", buffer);
        }
        
}

void han_fu(int sig_no){
    printf("signal...\n");
}

int main(int argc, char *argv[]){
    signal(SIGPIPE,han_fu);
    int sockfd,cr;
    struct linger l;
    l.l_onoff =1;
    l.l_linger = 2;
    struct sockaddr_in ca,sa;
    socklen_t len;
    len=sizeof(struct sockaddr_in);
    if(argc!=3){
        fprintf(stderr,"Usage %s  <IP>  <PORT>\n",argv[0]);
        return 1;
    }
    ca.sin_family=AF_INET;
    ca.sin_addr.s_addr=inet_addr(argv[1]);
    ca.sin_port=htons(atoi(argv[2]));
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd>0){
        fprintf(stderr,"Socket created success\n");
    }
    else{
        fprintf(stderr,"socket creat error\n");
    return 1;
    }
    cr=connect(sockfd,(struct sockaddr *)&ca,sizeof(ca));
    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &l, sizeof(l));
    if(cr==0){
        fprintf(stderr,"Connect success return=%d\n",cr);
        printf("Connected server details\n");
        getpeername(sockfd,(struct sockaddr *)&sa,&len);
        printf("Sver port=%d\n",ntohs(sa.sin_port)); 
        printf("Server IP=%s\n",inet_ntoa(sa.sin_addr));

    }
    else{
    fprintf(stderr,"Connect Error=%d\n",cr);
    perror("Connection...");
    exit(1);
    }
    str_cli(stdin, sockfd);
    return 0;
  }
