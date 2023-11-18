#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);  // Port number

    // Bind the socket to the specified address and port
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // Listen for incoming connections
    listen(serverSocket, 5);

    printf("Server listening on port 8080...\n");

    // Accept a client connection
    int clientSocket = accept(serverSocket, NULL, NULL);

    // Send a message to the client
    const char* message = "Hello, client!";
    send(clientSocket, message, strlen(message), 0);

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
