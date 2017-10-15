#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <string.h>  
#include <ctype.h> 
#include <time.h>
#include "linktable.h"  
#define CMD_MAX_LEN 10  

int Hello();
int Help();
int Show();
int Emoji();
int Ls();
int Date();
int Author();
int Quit();

typedef struct DataNode
{
	tLinkTableNode * pNext;
	char * cmd;
	char * desc;
	int(*handler)();
}tDataNode;

tDataNode * Findcmd(tLinkTable * head, char * cmd)
{
	tDataNode * pNode = (tDataNode *)GetLinkTableHead(head);
	while (pNode != NULL)
	{
		if (strcmp(pNode->cmd, cmd) == 0)
		{
			return pNode;
		}
		else
		{
			pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
		}
	}
	return NULL;
}

int ShowAllcmd(tLinkTable * head)
{
	tDataNode * pNode = (tDataNode *)GetLinkTableHead(head);
	printf("*******************************\n");
	while (pNode != NULL)
	{
		printf("************\n");
		printf("%s - %s\n", pNode->cmd, pNode->desc);
		pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
{
	*ppLinktable = CreateLinkTable();

	tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "hello";
	pNode->desc = "Welcome to my menu 3.0";
	pNode->handler = Hello;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "help";
	pNode->desc = "What can I do for you O.O ?";
	pNode->handler = Help;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "show";
	pNode->desc = "Show all menu cmd";
	pNode->handler = Show;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "emoji";
	pNode->desc = "the emoji expression: TAT $.$ >o<  ~^o^~ ";
	pNode->handler = Emoji;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "ls";
	pNode->desc = "List all file in this directory";
	pNode->handler = Ls;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "date";
	pNode->desc = "Show the current date";
	pNode->handler = Date;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "author";
	pNode->desc = "the menu 3.0 by Sunday647.L";
	pNode->handler = Author;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "quit";
	pNode->desc = "Exit the menu cmd\n";
	pNode->handler = Quit;
	AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
	return 0;
}

tLinkTable * head = NULL;

int main()
{
	InitMenuData(&head);
	while (1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Welcome to my menu 3.0 ,please input a cmd-->");
		scanf("%s", cmd);
		tDataNode *p = Findcmd(head, cmd);
		if (p == NULL)
		{
			printf("the menu doesn't include this cmd!\n");
			continue;
		}
		printf("%s - %s\n", p->cmd, p->desc);
		if (p->handler != NULL)
		{
			p->handler();
		}
	}
	return 0;
}

int Hello()
{
	return 0;
}
int Help()
{
	return 0;
}
int Show()
{
	ShowAllcmd(head);
	return 0;
}
int Emoji()
{
	return 0;
}
int Ls()
{
	system("ls");
	return 0;
}
int Date()
{
	time_t T;
	struct tm * timenow;
	time(&T);
	timenow = localtime(&T);
	printf("现在时间是: %s", asctime(timenow));
}
int Author()
{
	return 0;
}
int Quit()
{
	exit(0);
}