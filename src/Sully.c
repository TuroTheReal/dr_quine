#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
int i = 5;
char t[15];
char o[15];
char *c = "#include <stdio.h>%1$c#include <string.h>%1$c#include <stdlib.h>%1$c#include <unistd.h>%1$cint main(){%1$cint i = %3$d;%1$cchar t[15];%1$cchar o[15];%1$cchar *c = %2$c%4$s%2$c;%1$cif (i + 1) {%1$cif (access(%2$cSully_5.c%2$c, R_OK) != -1)%1$ci--;%1$cstrcat(t, %2$cSully_%2$c);%1$ct[6] = i + 48;%1$ct[7] = 0;%1$cstrcpy(o, t);%1$cstrcat(t, %2$c.c%2$c);%1$cvoid* fd = fopen(t, %2$cw%2$c);%1$cfprintf(fd, c, 10, 34, i, c, 37);%1$cfclose(fd);%1$cchar cmd[500];%1$csprintf(cmd, %2$cgcc -o %5$cs %5$cs && ./%5$cs%2$c, o, t, o);%1$cif (i)%1$csystem(cmd);%1$c}%1$c}";
if (i + 1) {
if (access("Sully_5.c", R_OK) != -1)
i--;
strcat(t, "Sully_");
t[6] = i + 48;
t[7] = 0;
strcpy(o, t);
strcat(t, ".c");
void* fd = fopen(t, "w");
fprintf(fd, c, 10, 34, i, c, 37);
fclose(fd);
char cmd[500];
sprintf(cmd, "gcc -o %s %s && ./%s", o, t, o);
if (i)
system(cmd);
}
}