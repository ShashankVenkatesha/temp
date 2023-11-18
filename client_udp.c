#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Initialize the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);  // Server port number

    // Send a message to the server
    const char* message = "Hello, server!";
    sendto(clientSocket, message, strlen(message), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // Close the socket
    close(clientSocket);

    return 0;
}
