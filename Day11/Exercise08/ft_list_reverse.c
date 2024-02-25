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

int ft_list_size(t_list *begin_list){
    t_list *curr;
    int len = 0;
    for (curr = begin_list; curr->next!=0x00; curr=curr->next){
        len++;
    }
    len++;

    return len;
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

void ft_list_reverse(t_list **begin_list){
    int list_size = ft_list_size(*begin_list);

    for (int i=0; i<(list_size/2); i++){
        t_list *s1 = ft_list_at(*begin_list, i);
        t_list *s2 = ft_list_at(*begin_list, list_size-1-i);
        void *temp_data = s1->data;
        s1->data = s2->data;
        s2->data = temp_data;
    }
}


int main(){

    t_list **list_array = (t_list**)malloc(sizeof(t_list));
    ft_list_push_back(list_array, "1 test data");
    ft_list_push_back(list_array, "2 test data");
    ft_list_push_back(list_array, "3 test data");
    ft_list_push_back(list_array, "4 test data");

    ft_list_reverse(list_array);

    return (0);
}
