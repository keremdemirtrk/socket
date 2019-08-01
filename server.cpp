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
        if(socket1 < 0)
            perror("Error var");
//Create Socket  
struct sockaddr_in serv_addr,client_addr;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(5000);
char buff[1024];
socklen_t clientlen = sizeof(client_addr);
    int bind1 = bind(socket1,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
        if(bind1 < 0)
            perror("bind error");
//bind

listen(socket1,5);

//listen

while(1){
    int client = accept(socket1,(struct sockaddr*)&client_addr,&clientlen);
    if(client<0)
        perror("accept error");

    int read1 = read(client,buff,1024);
    if(read1<0)
        perror("read error");
    printf("%s\n",buff);

    close(client);

}

    return 0;

}
