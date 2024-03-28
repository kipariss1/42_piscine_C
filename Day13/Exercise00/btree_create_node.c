#include <stdlib.h>
#include "ft_btree.h"

t_btree* btree_create_node(void *item){
    t_btree *res = malloc(sizeof(t_btree));
    res->item = item;
    res->left = NULL;
    res->right = NULL;

    return res;
}

int main(){

    int a = 5;
    char b[] = "test";

    t_btree *res1 = btree_create_node(&a);
    t_btree *res2 = btree_create_node(b);

    // free(res1);
    // free(res2);

    return (0);
}
