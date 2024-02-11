#include "ft_ultimate_fight.h"
#include "libft.h"
#include "libstr.h"

void ft_ultimate_fight(t_perso *attacker, t_perso *defendant, t_attack attack){

    char one_dead_template[] = " is dead \n";
    char fight_template1[] = " does a ";
    char fight_template2[] = " on ";
    char fight_template3[] = " \n";
    int len;
    if (attacker->life==0 && defendant->life==0){
        ft_putstr("There can be no fight, both are dead");
        return;
    }
    else if (attacker->life<=0){
        len = my_strlen(attacker->name) + my_strlen(one_dead_template); 
        char res_str[len];
        initstr(res_str, len);
        my_strcat(res_str, attacker->name);
        my_strcat(res_str, one_dead_template);
        ft_putstr(res_str);
        return;
    }
    else if (defendant->life<=0){
        len = my_strlen(defendant->name) + my_strlen(one_dead_template); 
        char res_str[len];
        initstr(res_str, len);
        my_strcat(res_str, defendant->name);
        my_strcat(res_str, one_dead_template);
        ft_putstr(res_str);
        return;
    }

    // printing attack
    char *attack_str = ATTACK_NAMES[attack];

    int len_attack = my_strlen(attacker->name)+my_strlen(fight_template1)+my_strlen(attack_str)+my_strlen(fight_template2)+my_strlen(defendant->name)+my_strlen(fight_template3);
    char res[len_attack];
    initstr(res, len_attack);
    my_strcat(res, attacker->name);
    my_strcat(res, fight_template1);
    my_strcat(res, attack_str);
    my_strcat(res, fight_template2);
    my_strcat(res, defendant->name);
    my_strcat(res, fight_template3);

    defendant->life = defendant->life - ATTACK_POINTS[attack];
    ft_putstr(res);

    if (defendant->life<=0){
        ft_ultimate_fight(attacker, defendant, DEAD);
    }
   
}

int main(){

    t_perso DonnieMatrix;
    DonnieMatrix.name = "Donnie Matrix";
    DonnieMatrix.life = 100;
    DonnieMatrix.age = 42;
    DonnieMatrix.profession = DOCTOR;
    t_perso FrauFarbissina;
    FrauFarbissina.name = "Frau Farbissina";
    FrauFarbissina.life = 100;
    FrauFarbissina.age = 20;
    FrauFarbissina.profession = SAVE_AUSTIN_LIFE;

    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK);
    ft_ultimate_fight(&FrauFarbissina, &DonnieMatrix, PUNCH);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, HEADBUTT);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK5);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK2);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK12);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK7);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK3);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, HEADBUTT);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK9);
    ft_ultimate_fight(&DonnieMatrix, &FrauFarbissina, KICK11);

    return (0);
}

