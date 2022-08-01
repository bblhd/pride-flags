#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define rgb(r, g, b) 16 + b + g * 6 + r * 36

void printFlagRow(int w, int c) {
	printf("\033[38:5:%im",c);
	for (int i = 0; i < w; i++) printf("█");
	printf("\n");
}

void printFlag(int w, int *cs) {
	for (; *cs; cs++) printFlagRow(w, *cs);
}

void print23Flag(int *cs) {
	int len = 0;
	for (; cs[len]; len++);
	for (; *cs; cs++) printFlagRow(len*5*3/2/2, *cs);
}

struct Flag {
	char *code;
	int colors[10];
};

#define ENDOFFLAGS {"", {}}

struct Flag flags[] = {
	{"rainbow", { rgb(4,1,1), rgb(5,3,1), rgb(5,4,1), rgb(0,2,1), rgb(1,1,3), rgb(2, 1, 3)} },
	{"les",     { rgb(3,1,0), rgb(5,3,2), rgb(5,5,5), rgb(4,2,3), rgb(3,0,2) } },
	{"gay",     { rgb(0,3,2), rgb(3,5,4), rgb(5,5,5), rgb(2,3,4), rgb(1,1,2) } },
	{"bi",      { rgb(4,0,2), rgb(4,0,2), rgb(3,1,3), rgb(0,1,3), rgb(0,1,3) } },
	{"trans",   { rgb(1,4,5), rgb(5,3,4), rgb(5,5,5), rgb(5,3,4), rgb(2,4,5) } },
	{"nb",      { rgb(4,4,1), rgb(5,5,5), rgb(3,2,4), rgb(1,1,1) } },
	{"ace",     {  rgb(0,0,0), rgb(3,3,3), rgb(5,5,5), rgb(3,0,3) } },
	ENDOFFLAGS
};
struct Flag *getFlagFromCode(char *code, struct Flag *flags) {
	for (; *flags->code != '\0'; flags++) {
		if (strcmp(flags->code, code) == 0) return flags;
	}
	return NULL;
}

int main(int argc, char *args[]) {
	srand(time(0));
	if (argc > 1) {
		struct Flag *flag = getFlagFromCode(args[1], flags);
		if (flag != NULL) print23Flag(flag->colors);
	} else {
		int numOfFlags = sizeof(flags)/sizeof(struct Flag) - 1;
		int random_number = rand() % numOfFlags;
		print23Flag(flags[random_number].colors);
	}
}
