#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

int main(int argc, char *argv[]){

    if (argc == 1){
        // Maybe here the reading of the standard output will be needed
        ft_putstr("No file specified");
        ft_putstr("\n");
    }

    // taking care of bytes argument
    int bytes_mode;
    int bytes_mode_flag_arg_pos;
    for (int i=0; argv[i]!=0x00; i++){
        (!ft_strcmp(argv[i], "-c") || !ft_strcmp(argv[i], "--bytes")) ? bytes_mode = 1, bytes_mode_flag_arg_pos = i : bytes_mode = 0;
    }

    int n_of_bytes = 0;
    if (bytes_mode_flag_arg_pos){ 
        if (!ft_str_is_numeric(argv[bytes_mode_flag_arg_pos+1])){
            ft_putstr("Invalid number of bytes: ");
            ft_putstr(argv[bytes_mode_flag_arg_pos+1]);
            ft_putstr("\n");
            return (-1);
        }
        n_of_bytes = ft_str_to_int(argv[bytes_mode_flag_arg_pos+1]); 
    }

    if (bytes_mode_flag_arg_pos){
        // TODO: tail file
    }

    (void)n_of_bytes;

    return (0);
}
