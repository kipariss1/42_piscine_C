#include "ft_door.h"

void ft_putstr(char *str){
    int i=0;

    while(str[i]){
        write(1, str+i, 1);
        i++;
    }

    char newline = '\n';

    write(1, &newline, 1);
}

ft_bool open_door(t_door *door){
    ft_putstr("Door opening ....");
    door->state = OPEN;

    return (TRUE);
}

ft_bool close_door(t_door *door){
    ft_putstr("Door closing ....");
    door->state = CLOSE;
    

    return (TRUE);
}

ft_bool is_door_open(t_door *door){
    ft_putstr("Door is open?");
    return (door->state == OPEN);
}

ft_bool is_door_close(t_door *door){
    ft_putstr("Door is close?");
    return (door->state == CLOSE);
}
