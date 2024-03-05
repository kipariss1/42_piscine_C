#include <unistd.h>
#include <fcntl.h>

void read_and_print_file(char *filepath){

    int fd = open(filepath, O_RDONLY);

    if (fd == -1){
        return;
    } 

    int file_size = lseek(fd, 0, SEEK_END); // offsetting 0 bytes from file end and getting the size of the file

    char buf[file_size+1];

    int read_len = read(fd, buf, file_size);
    buf[read_len+1] = '\0';

    for (int i=0; buf[i]!='\0'; i++){
        write(1, &buf[i], 1);
    }

}

int main(int argc, char *argv[]){

    int len;
    for (len = 0; argv[len]!=0x00; len++){}

    if (len == 1){
        write(1, "File name missing.", 18);
    }
    else if (len > 2){
        write(1, "Too many arguments.", 19);
    }

    read_and_print_file(argv[1]);

    return (0);
}
