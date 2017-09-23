#include<stdio.h>
#include<stdlib.h>
char add(char c);
int main()
{

    char cmd[128];
    int i;
	
    while(1)
    {

	scanf("%s",cmd);

	if(strcmp(cmd,"help")==0)
	{
	    printf("This is help cmd!\n");

	}	
	else if(strcmp(cmd,"hello")==0)
	{	

	    printf("This is hello!\n");

	}	
        else if(cmd[1] <= 65)
	{
 		add(cmd[1]);
		printf("%s",cmd[128]);
	}
        else if(strcmp(cmd,"hello world!")==0)
	{
	    for(i=0;i<=5;i++)
		cmd[i]='x';
		printf("%s",cmd[128]);
	}
	else if(strcmp(cmd,"quit")==0)
	{
		exit(0);
	}
	else
	{
	    printf("Wrong cmd!\n");

	}
    }    	
    return 0;
}

char add(char c)
{
    c+=1;
    return c;

}
