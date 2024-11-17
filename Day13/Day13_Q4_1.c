#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE   "/tmp/mysock"

int main() {
    int ret, cli_fd;
    int arr[2];
    struct sockaddr_in serv_addr;
    char msg[512];
    //4. create client socket
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    //5. connect to server socket
    serv_addr.sun_family = AF_INET;
    strcpy(serv_addr.sun_path, SOCK_FILE);
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    do {
        //7. send data to server
        printf("client: ");
        arr[0]=12;
        arr[1]=11;
        write(cli_fd, arr, sizeof(arr));
        //10. read data from server
        read(cli_fd, msg, sizeof(arr));
        for(int i=0;i<=1;i++){
        printf("server: %s\n", arr[i]);
        };
    //11. close client socket
    close(cli_fd);
    return 0;
}
