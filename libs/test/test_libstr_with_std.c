#include "libstr_with_std.h"
#include "libft.h"

int main(){
    char str[] = "eggs, bread, butter, milk";

    char **res = split_string(str, ',');

    for (int i=0; res[i]!=0; i++){
        ft_putstr(res[i]);
    }

    return (0);
}
