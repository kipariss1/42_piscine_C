#ifndef __LIBSTR_H__
#define __LIBSTR_H__

extern const int L_BIG;         // low border of big letters in ascii
extern const int H_BIG;         // high border of big letters in ascii
extern const int L_SMALL;       // low border of small letters in ascii
extern const int H_SMALL;       // high border of small letters in ascii
extern const int OFFSET;        // offset from uppercase to lowercase in ascii

void initstr(char *str, unsigned int strlen);                    // init string in main(): assign '\0' to every member of char array
int my_strlen(char *str);                                           // find length of string
char* my_strcat(char *dest, char *src);                             // concatinate strings, destination has to have enough space
char* my_strcpy(char *dest, char *src);                             // copy string from src to destination, dest has to have enought space
unsigned int my_strlcat(char *dest, char *src, unsigned int size);  // concatinate strings, size - size of dest, doesn't overflow dest, return n of concatinated chars from src 
char* my_strncat(char *dest, char *src, int n);                     // concatinate strings, n - wanted amount of chars from src, which will be concatinated
char* my_strncpy(char* dest, char* src, unsigned int n);            // copy string to dest, n - wanted amount of chars from src, which will be copied
int is_uppercase(char ch);                                          // checks if char us uppercase
int is_letter(char ch);                                             // checks if char is a letter
int strcmp(char *str1, char *str2);                                 // compares strings, returnes difference of first different char in strings
void strip_non_letters(char *str);                                  // strips non letter chars from beginning and end of the string
void to_lowercase(char *str);                                       // makes string lowercase

#endif
