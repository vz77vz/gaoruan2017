#ifndef _LINK_TABLE_H_  
#define _LINK_TABLE_H_  
typedef struct LinkTableNode
{
	struct LinkTableNode *pNext;
}tLinkTableNode;

typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int SumOfNode;
}tLinkTable;

//Create a linktable  
tLinkTable * CreateLinkTable();
//Delete linktable  
int DeleteLinkTable(tLinkTable * pLinkTable);
//Add a linktable node  
void AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
//Delete a linktable node  
int DeleteLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
//Get link table head  
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);
//Get next link table node  
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
#endif  
