#include "duLinkedList.h"
#define NULL 0
#include<stdlib.h>
#include<stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!(*L)) return ERROR;
	(*L)->prior = (*L)->next = *L;
	printf("The operation has completed.\n");
	return SUCCESS; 

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	
	DuLNode*p = *L ;
	while(p){
		
		p = p->next;
		free(*L);
		*L = p;
	}
	free(p);
	printf("The list is destroyed!\n");

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	
	if(p== NULL||q == NULL||p->prior == NULL) return ERROR;
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	printf("The operation has completed.\n");
	return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	
	if(p == NULL||q == NULL||p->prior == NULL) return ERROR;
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	printf("The operation has completed.\n");
	return SUCCESS;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	
	if(p == NULL||p->next == NULL) return ERROR;
	DuLNode*q = p->next; 
	*e = q->data;
	p->next = q->next ;
	q->next->prior = p;
	printf("The data of the deleted node is %d\n",*e);
	printf("The node is deleted!\n");
	return SUCCESS;


}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
	printf("The list is :\n");
	DuLNode*p = L;
	while(p){
		
		visit(p->data);
		p = p->next;
		
	}
	free(p);

}
//遍历时输出链表数据的函数 
void visit(ElemType e){
	
	printf("%d ",e);
}

/**
 * 	    @name        : LNode* FindNode(LinkedList list, ElemType n)
 *	@description : find the first node according to n
 *	@param	     : list(the head node), n
 *	@return	     : LNode
 *  	@notice      : choose to finish
 */
DuLNode* FindNode(DuLinkedList list, ElemType n)
{
    while (list) {
        if (list->data == n)
            return list;
        list = list->next;
    }
    printf("The node does not exit.\n");
    return NULL;
}
