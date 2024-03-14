#include <stdio.h>
 int main(){
char statement[4][6] =
 {"HELLO\0","HOW\0\0\0","ARE\0\0\0","DOING\0"};
 char *ptr[] =
 {statement[0],statement[1],statement[2],statement[3]};
 char **pptr[] = {ptr,ptr+2,ptr+1,ptr+3};
 char ***p = pptr;
 printf("%s ",**p);
 printf("%s ",**(p+2));
 printf("%s ",**(p+1));
 printf("%s ",**(p+3));
 return 0;
 }