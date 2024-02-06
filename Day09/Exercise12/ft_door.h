#ifndef __FT_DOOR_H__
#define __FT_DOOR_H__

#include <unistd.h>

typedef enum {
    FALSE, 
    TRUE,
} ft_bool;

typedef enum {
    CLOSE,
    OPEN,
} t_door_state;

typedef struct s_door
{

    t_door_state state;

} t_door;

// typedef enum {
//     EXIT_SUCCSESS = 0,
// } t_exit_status;

void ft_putstr(char *str);
ft_bool open_door(t_door *door);
ft_bool close_door(t_door *door);
ft_bool is_door_open(t_door *door);
ft_bool is_door_close(t_door *door);

#endif