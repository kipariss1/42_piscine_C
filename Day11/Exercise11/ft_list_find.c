#include "ft_list.h"
#include <stdlib.h>

t_list* ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)()){
    for (t_list *curr = begin_list; curr != 0; curr = curr->next){
        if (!cmp(data_ref, curr->data)){
            return curr;
        }
    } 
    return 0;
}

int compare_func(char *s1, char *s2){
    return *s1-*s2;
}

char *reference = "3 test data";

void replace_to_zero(char *digit){
    char replacement = '0';
    digit[0] = replacement;
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
    char a[] = "1 test data";
    char b[] = "2 test data";
    char c[] = "3 test data";
    char d[] = "4 tets data";
    char e[] = "5 test data";
    ft_list_push_back(list_array, a);
    ft_list_push_back(list_array, b);
    ft_list_push_back(list_array, c);
    ft_list_push_back(list_array, d);
    ft_list_push_back(list_array, e);

    t_list *res = ft_list_find(*list_array, "4 test data", compare_func);

    return (0);
}
