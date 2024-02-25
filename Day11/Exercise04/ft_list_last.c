#include "ft_list.h"
#include <stdlib.h>

t_list* ft_list_last(t_list *begin_list){
    t_list *last;
    for (last=begin_list; last->next!=0x00; last=last->next){
        int a = 5;
    }

    return last;    
}

void ft_list_push_back(t_list **begin_list, void *data){
    if (*begin_list==0){
        *begin_list = (t_list*)malloc(sizeof(t_list));
        (*begin_list)->data = data;
        return;
    }

    t_list *last; 
    for (last = *begin_list; last->next!=0x00; last = last->next){}

    t_list *new = (t_list*)malloc(sizeof(t_list));
    new->data = data;
    last->next = new;

}

int main(){

    t_list **list_array = (t_list**)malloc(sizeof(t_list));
    ft_list_push_back(list_array, "1 test data");
    ft_list_push_back(list_array, "2 test data");

    t_list *last = ft_list_last(*list_array);
    char *last_data = last->data;

    return (0);
}
