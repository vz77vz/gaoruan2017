#include <stdio.h>  
#include <stdlib.h>  
#include "linktable.h"  

tLinkTable* CreateLinkTable()
{
	tLinkTable* pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	return pLinkTable;
}
int DeleteLinkTable(tLinkTable * pLinkTable)
{
	tLinkTableNode * p;
	while (pLinkTable->pHead != pLinkTable->pTail)
	{
		p = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		free(p);
	}
	free(pLinkTable->pHead);
	free(pLinkTable);
}
void AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if (pLinkTable->pHead == NULL)
	{
		pLinkTable->pHead = pNode;
		pLinkTable->pTail = pNode;
		pLinkTable->SumOfNode = 1;
	}
	else
	{
		pLinkTable->pTail->pNext = pNode;
		pLinkTable->pTail = pNode;
		pLinkTable->SumOfNode += 1;
	}
}
int DeleteLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if (pLinkTable == NULL || pNode == NULL)
	{
		return -1;
	}
	if (pLinkTable->pHead == pNode)
	{
		pLinkTable->pHead == pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1;
		if (pLinkTable->SumOfNode == 0)
		{
			pLinkTable->pTail = NULL;
		}
		return 0;
	}
	tLinkTableNode *p = pLinkTable->pHead;
	while (p != NULL)
	{
		if (p->pNext == pNode)
		{
			tLinkTableNode *q = p->pNext->pNext;
			p->pNext = q;
			free(q);
			pLinkTable->SumOfNode -= 1;
			if (pLinkTable->SumOfNode == 0)
			{
				pLinkTable->pTail = NULL;
			}
			return 0;
		}
		p = p->pNext;
	}
	return -1;
}
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable)
{
	if (pLinkTable == NULL)
	{
		return NULL;
	}
	return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
	if (pLinkTable == NULL || pNode == NULL)
	{
		return NULL;
	}
	tLinkTableNode *p = pLinkTable->pHead;
	while (p != NULL)
	{
		if (p == pNode)
		{
			return p->pNext;
		}
		p = p->pNext;
	}
	return NULL;
}