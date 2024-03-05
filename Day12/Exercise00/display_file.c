#include <unistd.h>
#include <fcntl.h>

char newline = '\n';

void read_and_print_file(char *filepath){

    int fd = open(filepath, O_RDONLY);

    if (fd == -1){
        return;
    } 

    int file_size = lseek(fd, 0, SEEK_END); // offsetting 0 bytes from file end and getting the size of the file
    lseek(fd, 0, SEEK_SET);                 // move offset to the beginning of the file

    char buf[file_size];

    int read_len = read(fd, buf, file_size);
    buf[read_len] = '\0';

    for (int i=0; buf[i]!='\0'; i++){
        write(1, &buf[i], 1);
    }

    write(1, &newline, 1);
}

int main(int argc, char *argv[]){

    int len;
    for (len = 0; argv[len]!=0x00; len++){}

    if (len == 1){
        write(2, "File name missing.", 18);
        write(2, &newline, 1);
        return (1);
    }
    else if (len > 2){
        write(2, "Too many arguments.", 19);
        write(2, &newline, 1);
        return (1);
    }

    read_and_print_file(argv[1]);

    (void)argc;

    return (0);
}
