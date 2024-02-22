#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
int keymap[max];
void permutation()
{
	for(int i=0;i<strlen(key);i++)
	{
		keymap[key[i]]=i;
		
	}
}
char* encrypt(char* msg)
{
	int r,c,j,k=0;
	char cipher[max]="";
	col=strlen(key);
	row=strlen(msg)/col;
	if(strlen(msg)%col)
	{
		row+=1;
	}
	char matrix[r][c]
}
