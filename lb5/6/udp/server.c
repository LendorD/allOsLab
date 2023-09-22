#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8888
#define SERVER_BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[SERVER_BUFFER_SIZE];
    FILE *file;
    int received, written;

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd == -1) {
        perror("Cannot create server socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl("10.0.1.0");

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(1);
    }

    printf("Using default port %d\n", SERVER_PORT);

    while (1) {
        client_addr_len = sizeof(client_addr);

        received = recvfrom(server_fd, buffer, SERVER_BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
        if (received == -1) {
            perror("Receive failed");
            continue;
    	}
	printf( "Some client sent: %s\n",buffer);
    }

    fclose(file);
    close(server_fd);

    return 0;
}

