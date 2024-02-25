#include "ft_list.h"
#include <stdlib.h>

t_list* ft_list_at(t_list *begin_list, unsigned int nbr){
    t_list *curr;
    int i=0;
    for (curr = begin_list; curr->next!=0x00 && i<nbr; curr=curr->next){
        i++;
    }

    if (i<nbr){
        return 0x00;
    }

    return curr;
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
    ft_list_push_back(list_array, "3 test data");

    t_list *list_at = ft_list_at(*list_array, 1);
    char *list_at_data = list_at->data;

    return (0);
}