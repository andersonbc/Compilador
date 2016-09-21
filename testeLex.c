%{
	#define D 300
	#define X 399
	#include <stdio.h>
	#include <stdlib.h>
	
%}

digito [1-9][0-9]*



%%
digito {return D;}

. {}
<<EOF>> {return X;}




%%

int main(int argc, char *argv[])
{
	FILE *f_in;
	int tipoToken;
	int totalDec = 0;

	if(argc == 2)
	{
		if(f_in == fopen(argv[1], "r"))
		{
			yyin = f_in;
		}
		else
		{
			perror(argv[0]);
		}
	}
	else
	{
		yyin = stdin;
	}
	while((tipoToken = yylex()) != X)
	{
		switch(tipoToken)
		{
			case D:
				++totalDec;
				break;
		}
	}
	printf("%d\n", totalDec);
	
}