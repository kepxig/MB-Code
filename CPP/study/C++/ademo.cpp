#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ID 6 //标识符
#define INT 7 //整数
#define LT 8 //<
#define LE 9 //<=
#define EQ 10 //=
#define NE 11 //<>
#define GT 12 //>
#define GE 13 //>=
int main()
{
	FILE* fp = fopen("test.txt", "r");
	char token[20];
	extern int lookup(char*);
	extern void out(int, char*);
	char ch;
	int i, c;
	ch = fgetc(fp);
	if (isalpha(ch)) /*it must be a identifer!*/
	{
		token[0] = ch;
		ch = fgetc(fp);
		i = 1;
		while (isalnum(ch))
		{
			token[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		token[i] = '＼0';
		fseek(fp, -1, 1); /* retract*/
		c = lookup(token);
		if (c == 0)
			out(ID, token);
		else
			out(c, ' ');
	}
	else if (isdigit(ch))
	{
		token[0] = ch;
		ch = fgetc(fp);
		i = 1;
		while (isdigit(ch))
		{
			token[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		token[i] = '\0';
		fseek(fp, -1, 1);
		out(INT, token);
	}
	else
		switch (ch)
		{
		case '<':
			ch = fgetc(fp);
			if (ch == ' = ')
				out(LE, ' ');
			else if (ch == '>')
				out(NE, ' ');
			else
			{
				fseek(fp, -1, 1);
				out(LT, ' ');
			}
			break;
		case '=':
			out(EQ, ' ');
			break;
		case '>':
			ch = fgetc(fp);
			if (ch == ' = ')
				out(GE, ' ');
			else
			{
				fseek(fp, -1, 1);
				out(GT, ' ');
			}
			break;
		default:
			reportError();
			break;
		}
	return;
}
