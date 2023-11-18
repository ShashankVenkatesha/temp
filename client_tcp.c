#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);  // Server port number

    // Connect to the server
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // Receive data from the server
    char buffer[1024];
    recv(clientSocket, buffer, sizeof(buffer), 0);

    // Display the received message
    printf("Message from server: %s\n", buffer);

    // Close the socket
    close(clientSocket);

    return 0;
}
