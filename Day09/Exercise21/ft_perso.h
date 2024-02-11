#ifndef __FT_PERSO_H__
#define __FT_PERSO_H__

inline char* strdup(char *str){
    return str;
}

typedef enum 
{

    DOCTOR,
    ENGINEER,
    SAVE_AUSTIN_LIFE,

} t_profession;

typedef struct s_perso
{

    char *name;
    double life;
    int age;
    t_profession profession;
    

} t_perso;


#endif