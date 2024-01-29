#include <unistd.h>
#include <stdio.h>

void ft_takes_place(int hour){

    char template[] = "THE FOLLOWING TAKES PLACE BETWEEN XX.00 X.M. AND XX.00 X.M. \n";
    // FROM "OPTIONS"
    int from_first_digit_place = 34;
    int from_second_digit_place = 35;
    int first_a_or_p_option_place = 40;
    // TO "OPTIONS"
    int to_first_digit_place = 49;
    int to_second_digit_place = 50;
    int second_a_or_p_option_place = 55;
    int ascii_offset = 48;

    if (hour == 0 || hour==24){
        template[from_first_digit_place] = '1';
        template[from_second_digit_place] = '2';
        template[first_a_or_p_option_place] = 'A';
        template[to_first_digit_place] = '0';
        template[to_second_digit_place] = '1';
        template[second_a_or_p_option_place] = 'P';
    }
    else if (hour>0 && hour<12){
        template[from_first_digit_place] = hour/10 + ascii_offset;
        template[from_second_digit_place] = hour%10 + ascii_offset;
        template[first_a_or_p_option_place] = 'A';
        template[to_first_digit_place] = (hour+1)/10 + ascii_offset;
        template[to_second_digit_place] = (hour+1)%10 + ascii_offset;
        template[second_a_or_p_option_place] = (hour==11) ? 'P' : 'A';
    }
       else if (hour>=12 && hour<24){
        template[from_first_digit_place] = (hour==12) ? hour/10 + ascii_offset : (hour-12)/10 + ascii_offset;
        template[from_second_digit_place] = (hour==12) ? hour%10 + ascii_offset : (hour-12)%10 + ascii_offset;
        template[first_a_or_p_option_place] = 'P';
        template[to_first_digit_place] = (hour-12+1)/10 + ascii_offset;
        template[to_second_digit_place] = (hour-12+1)%10 + ascii_offset;
        template[second_a_or_p_option_place] = 'P';
    }
    else{
        for (int i=0; template[i]!='\0'; i++){template[i]='\0';}
    }

    int len_of_template;
    for (len_of_template=0; template[len_of_template]; len_of_template++){}

    write(1, template, len_of_template);
}

int main(){
    ft_takes_place(0);

    return (0);
}
