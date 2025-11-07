#include <stdio.h>
void qd(void) {}
int main(void) {
	char *c = "#include <stdio.h>%cvoid qd(void) {}%cint main(void) {%c%cchar *c = %c%s%c;%c%cprintf(c, 10, 10, 10, 9, 34, c, 34, 10, 9, 10, 9, 10, 47, 10, 10, 47, 10, 10, 47, 10, 10, 47);%c%cqd();%c%c*%cinside%c*%c%c}%c%c*%coutside%c*%c";
	printf(c, 10, 10, 10, 9, 34, c, 34, 10, 9, 10, 9, 10, 47, 10, 10, 47, 10, 10, 47, 10, 10, 47);
	qd();
/*
inside
*/
}
/*
outside
*/