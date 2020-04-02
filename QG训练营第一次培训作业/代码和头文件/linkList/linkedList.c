#include "linkedList.h"
#define NULL 0
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	
	*L = (LinkedList) malloc (sizeof(LNode));
	if (!(*L)) return ERROR; 
	(*L)->next = NULL;
	printf("The linked list is initialized!\n");
	return SUCCESS;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	
	LNode*p = *L ;
	while(p){
		
		p = p->next;
		free(*L);
		*L = p;
	}
	printf("The linked list is destroyed!\n");

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	
	if(p == NULL||q == NULL)  return ERROR;
	q->next = p->next;
	p->next = q;
	printf("The node has been inserted successfully!\n");
	return SUCCESS;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	
	if(p == NULL||p->next == NULL) return ERROR;
	LNode*q = p->next; 
	*e = q->data;
	p->next = q->next ;
	free(q);
	printf("The node is deleted!\n");
	return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	
	printf("The linked list is :\n");
	LNode*p = L->next;
	while(p){
		
		visit(p->data);
		p = p->next;
		
	}
	printf("\n");

}
//遍历时输出链表数据的函数 
void visit(ElemType e){
	
	printf("%d ",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
 //搜索到相关结点则返回SUCCESS，否则，返回ERROR
Status SearchList(LinkedList L, ElemType e) {
	
	if(L->next == NULL){
		
		printf("there are not nodes behind the node!\n");
		return ERROR;
		
	}
	LNode*p = L->next; 
	while(p->data != e&&p != NULL){
		
		p = p->next;
	}
	if(p){
		
		printf("The value you are looking for is in the linked list.\n");
		return SUCCESS;
		
	}
	else{
		
		printf("The value you are looking for does not exist!\n");
		return ERROR;
		 
	}

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	
	if(!L) return ERROR;
	LNode*p,*q,*r;
	p = (*L)->next;           //记录第一个结点的地址 
	(*L)->next = NULL;        //第一个结点指向空 
	q = r =NULL; 
	while(p){
		
		q= p->next;      //记录下一结点的地址 
		p->next = r;     //反转当前结点 
		r = p;            
		p = q;           //结点后移
	} 
	(*L)->next = r;        //第一个结点指向最后一个结点 
	printf("The linked list is reversed.\n");
	return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 //使用快慢指针，若有环则返回SUCCESS 
Status IsLoopList(LinkedList L) {
	
	if(L ==NULL||L->next == NULL) return ERROR;
	LNode*fast,*slow;
	fast = slow = L;
	while(1){
		
		if(fast==NULL||slow==NULL||fast->next==NULL){
			
			printf("the linked list is not looped.\n");
			return ERROR;
			
		} 
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			
			printf("the linked list is looped.\n");
			return SUCCESS;
			
		} 
	}
	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	
	
	
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	
	if(*L==NULL||(*L)->next == NULL) return *L; 
	LNode*fast,*mid;
	fast = mid = *L;
	while(fast){
		
		if(fast->next == NULL) fast = fast->next;
		else  fast = fast->next->next;            //节点个数分奇偶 
		mid = mid->next;
	}
	printf("The middle node has been found.\n");
	return mid;

}
/**
 * 	    @name        : LNode* FindNode(LinkedList list, ElemType n)
 *	@description : find the first node according to n
 *	@param	     : list(the head node), n
 *	@return	     : LNode
 *  	@notice      : choose to finish
 */
LNode* FindNode(LinkedList list, ElemType n)
{
    while (list) {
        if (list->data == n){
        	
        	printf("The node has been found.\n");
        	return list;
		}
        list = list->next;
    }
    printf("The node does not exit.\n");
    return NULL;
}

