#include<stdio.h>
#include<string.h>
int main()
{
	int k;
	char plain[100],cipher[100],decrypt[100];
	printf("enter plain text:");
	scanf("%s",&plain);
	printf("enter key value:");
	scanf("%d",&k);
	int n=strlen(plain);
	for(int i=0;i<n;i++)
	{
		if(plain[i]>='a' && plain[i]<='z')
		{
			cipher[i]=(plain[i]-'a'+k)%26+'a';
		}
		if(plain[i]>='A' && plain[i]<='Z')
		{
			cipher[i]=(plain[i]-'A'+k)%26+'A';
		}
	}
	printf("\n encrypted text is:%s",cipher);
	for(int i=0;i<n;i++)
	{
		if(cipher[i]>='a' && cipher[i]<='z')
		{
			decrypt[i]=(cipher[i]-'a'-k)%26+'a';
		}
		if(cipher[i]>='A' && cipher[i]<='Z')
		{
			decrypt[i]=(cipher[i]-'A'-k)%26+'A';
		}
	}
	printf("\n decrypted text:%s",decrypt);
}
