#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main(){
    int socket1 = socket(AF_INET, SOCK_STREAM,0);
    if(socket1<0)
        perror("socket error");

struct sockaddr_in serv_addr;
struct hostent *host;
    serv_addr.sin_family=AF_INET;
    host = gethostbyname("127.0.0.1");
    serv_addr.sin_port = htons(5005);

    int connect1 = connect(socket1,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if(connect1<0)
        perror("connect erroroıkş");

    char message[1024];
    printf("mesajınızı yazınız:\n");
    fgets(message,1024,stdin);
    printf("Mesajınız: %s\n",message);

    int send1 = send(socket1,message,strlen(message),0);
    if(send1<0)
        perror("send error");

printf("mesajınız başarıyla gönderildi:\n");
    close(socket1);


    return 0;
}