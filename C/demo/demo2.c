#include<stdio.h>

int main()
{	
	FILE *fp=fopen("test.txt","r");
	char ch;
	ch = fgetc(fp);
	printf (ch);
	return 0;
}