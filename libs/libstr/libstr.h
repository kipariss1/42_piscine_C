#ifndef __LIBSTR_H__
#define __LIBSTR_H__

extern const int L_BIG;
extern const int H_BIG;
extern const int L_SMALL;
extern const int H_SMALL;
extern const int OFFSET;

int is_uppercase(char ch);
int is_letter(char ch);
int strcmp(char *str1, char *str2);
void strip_non_letters(char *str);
void to_lowercase(char *str);

#endif
