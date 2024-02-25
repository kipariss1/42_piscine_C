#include "ft_list.h"
#include <stdlib.h>

void ft_list_push_back(t_list **begin_list, void *data){
    if (*begin_list==0){
        *begin_list = (t_list*)malloc(sizeof(t_list));
    }

    t_list *curr; 
    for (curr = *begin_list; curr->next!=0x00; curr = curr->next){}

    curr->data = data;
    curr->next = (t_list*)malloc(sizeof(t_list));

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

int main(){

    t_list **list_array = (t_list**)malloc(sizeof(t_list));
    ft_list_push_back(list_array, "1 test data");
    ft_list_push_back(list_array, "2 test data");

    int res = ft_list_size(*list_array);

    return (0);
}