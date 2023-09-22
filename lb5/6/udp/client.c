#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8888
#define CLIENT_BUFFER_SIZE 100

int sendFix(int sock, char* buf, int flags);
int readFix(int sock, char* buf, int bufSize, int flags);

int main(int argc, char *argv[]) {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[CLIENT_BUFFER_SIZE];
    FILE *file;
    int len, sent;

    char tmp[12]={0x0};
    int pid = getpid();
    sprintf(tmp,"%d", pid);


    //if (argc < 2) {
    //    printf("Usage: %s filename\n", argv[0]);
    //    exit(1);
    //}

    file = fopen("testFile.txt", "r");
    if (file == NULL) {
        perror("Cannot open file");
        exit(1);
    }

    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd == -1) {
        perror("Cannot create client socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("10.0.1.0");

    while (1) {
	printf("Input request (empty to exit)\n");
        bzero(buffer,100);
        //fgets(buf, 100, stdin);
        char s[90];
        if (fgets(s, 90, file)==NULL) exit(0);
        strcat(buffer, tmp);
        strcat(buffer, " : ");
        strcat(buffer, s);
        buffer[strlen(buffer)-1] = '\0';
        if(strlen(buffer) == 0) {
            printf("Bye-bye\n");
	    return 0;
	}

        sent = sendto(client_fd, buffer, len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
       if (sent == -1) {
           perror("Cannot send data to server");
           exit(1);
       }
	//int res = sendFix(client_fd, buffer,0);
    //if ( res <= 0 ) {
    //  perror( "Error while sending:" );
    //  exit( 1 );
    //}
    //bzero(buffer,100);
    //res = readFix(client_fd, buffer, 100, 0);
    //if ( res <= 0 ) {
    //  perror( "Error while receiving:" );
    //  exit(1);
    //}

	printf("Server's response: %s\n",buffer);
    }

    fclose(file);
    close(client_fd);

    return 0;
}

int readFix(int sock, char* buf, int bufSize, int flags) {
  // читаем "заголовок" - сколько байт составляет наше сообщение
  unsigned msgLength = 0;
  int res=recv(sock,&msgLength,sizeof(unsigned),flags|MSG_WAITALL);
  if (res <= 0)return res;
  if(res > bufSize) {
    printf("Recieved more data, then we can store, exiting\n");
    exit(1);
  }
  // читаем само сообщение
  return recv(sock, buf, msgLength, flags | MSG_WAITALL);
}

int sendFix(int sock, char* buf, int flags) {
  // число байт в сообщении
  unsigned msgLength = strlen(buf);
  int res = send(sock, &msgLength, sizeof(unsigned), flags );
  if (res <= 0) return res;
  send(sock, buf, msgLength, flags);
}

