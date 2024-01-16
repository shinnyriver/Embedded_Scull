#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define DEVICE_ROUTE "/dev/scull0"

void write_scull(const char* data){
    int fd = open(DEVICE_ROUTE, O_WRONLY);
    if(fd==-1){
        perror("Device File Open Error!");
        exit(EXIT_FAILURE);
    }

    ssize_t num_write = write(fd, data, strlen(data));
    if(num_write==-1){
        perror("Device File Write Error!");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("%ld bytes written\n", num_write);
    printf("%s written\n", data);
    close(fd);
}

void read_scull(){
    int fd = open(DEVICE_ROUTE, O_RDONLY);
    if(fd==-1){
        perror("Device File Open Error!");
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    ssize_t num_read = read(fd, buf, 1024);
    if(num_read==-1){
        perror("Device File Read Error!");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("%ld bytes read\n", num_read);
    printf("%s read\n", buf);
    close(fd);
}

int main() {
    const char* data_to_write = "Hello, Scull!";

    write_scull(data_to_write);
    read_scull();

    return 0;
}