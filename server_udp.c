#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Initialize the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);  // Port number

    // Bind the socket to the specified address and port
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    printf("Server listening on port 8080 for UDP...\n");

    // Receive data from the client
    char buffer[1024];
    struct sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddress, &clientAddrLen);

    // Display the received message
    printf("Message from client: %s\n", buffer);

    // Close the socket
    close(serverSocket);

    return 0;
}
