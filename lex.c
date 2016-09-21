%{
	#define D 300
	#include <stdio.h>
	#include <stdlib.h>

%}

digito [1-9][0-9]*
DIGIT 		[0-9]
HEX 		0x[0-9A-Fa-f]+
FLOAT 		{DIGIT}*\.{DIGIT}+|{DIGIT}+\.{DIGIT}*
DECIMAL 	{DIGIT}+
OCTAL		[0-7]
CHAR 		[a-zA-Z]
SPACE   	[\ \t]
DELIM 		{SPACE}+
ID {CHAR}({CHAR}|{DIGIT})*
STRING {CHAR}?\"(\\.|[^\\"])*\"|{CHAR}?\'(\\.|[^\\'])*\'


%%
digito {return D;}



%%

void main()
{
	int val, total = 0, n = 0;
	while ( (val = yylex()>0) ){
		switch(val){
			case D:
				++total;
				break;
		}


	}
	total++;
	printf("ave = %d\n", total);
}
