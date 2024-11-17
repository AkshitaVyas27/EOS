#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE   "/tmp/mysock"

int main() {
    int ret, serv_fd, cli_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t socklen = sizeof(cli_addr);
    int arr[2];
    int arr1[2];
    //1. create server socket
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    //2. bind the address
    serv_addr.sun_family = AF_INET;
    strcpy(serv_addr.sun_path, SOCK_FILE);
    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //3. listen to server socket
    listen(serv_fd, 5);
    //6. accept client connection
    cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
    
        //8. read data from client
        read(cli_fd, arr, sizeof(arr));
        if(int i=0;i<=2;i++){
        printf("client: %s\n", arr[i]);
        }
        //9. send data to client
        arr1[0]=arr[0]+arr[1];
        arr1[1]=0;
        write(cli_fd, arr1, sizeof(arr1));
   
    //12. close client socket
    close(cli_fd);
    //13. shutdown server socket
    shutdown(serv_fd, SHUT_RDWR);
    //14. delete the socket file
    unlink(SOCK_FILE);
    return 0;
}
