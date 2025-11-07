#include <stdio.h>
#define FILE "Grace_kid.c"
#define CODE "#include <stdio.h>%c#define FILE %c%s%c%c#define CODE %c%s%c%c#define FT(x)int main(){fprintf(fopen(FILE, x), CODE, 10, 34, FILE, 34, 10, 34, CODE, 34, 10, 10, 34, 119, 34, 10, 47, 10, 10, 47);}%cFT(%c%c%c)%c%c*%cmycomment%c*%c"
#define FT(x)int main(){fprintf(fopen(FILE, x), CODE, 10, 34, FILE, 34, 10, 34, CODE, 34, 10, 10, 34, 119, 34, 10, 47, 10, 10, 47);}
FT("w")
/*
mycomment
*/