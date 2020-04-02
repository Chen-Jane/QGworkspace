#include "dulinkedList.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void visit(ElemType e);
void PrintWindows();
void PauseAndGo(); 
Status CreateList(DuLinkedList* L);

int main(){
	
	DuLinkedList head = NULL;
	DuLinkedList head2= NULL; 
	ElemType deletedata;
	char option;
	CreateList(&head); 
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");InitList_DuL(&head2); PauseAndGo(); break;
			case'B':system("cls");DestroyList_DuL(&head); PauseAndGo(); break;
			case'C':system("cls");ElemType pdata,qdata;DuLNode* pnode,*qnode;qnode =(DuLinkedList) malloc(sizeof(DuLNode)); 
			                      if (qnode == NULL) { printf("Error : malloc faile in case 'C'.\n"); PauseAndGo(); break; }
		                          printf("请输入所要插入位置后的节点值：");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("请输入要插入的节点的值：");scanf("%d",&qdata);qnode->data = qdata;
								  InsertBeforeList_DuL(pnode, qnode); TraverseList_DuL(head, visit);PauseAndGo(); break;         
			case'D':system("cls");{ElemType pdata,qdata;DuLNode* pnode; DuLNode* qnode = (DuLinkedList)malloc(sizeof(DuLNode));
			                      if (qnode == NULL) { printf("Error : malloc faile in case 'D'.\n"); PauseAndGo(); break; }
		                          printf("请输入所要插入位置前的节点值：");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("请输入要插入的节点的值：");scanf("%d",&qdata);qnode->data = qdata; 
								  InsertAfterList_DuL(pnode, qnode);TraverseList_DuL(head, visit);} PauseAndGo(); break;     					  
		    case'E':system("cls");ElemType a; printf("输入想要删除的节点的前一个结点存储的值 ： "); scanf("%d", &a);
                                  DuLNode* b;b = FindNode(head, a);
                                  DeleteList_DuL(b, &deletedata);TraverseList_DuL(head, visit);PauseAndGo();break;
		    case'F':system("cls");TraverseList_DuL(head, visit);PauseAndGo();break;
		    default: return 0;
		}
	} 
} 
//创建双链表 
Status CreateList(DuLinkedList* L){
	
	char ch;
	DuLNode*p=NULL,*q=NULL;
	*L = NULL;
	p=(DuLinkedList) malloc (sizeof(DuLNode));
	//if(p==NULL) return ERROR;
	printf("请输入一串整数并用空格隔开，按回车运行:\n");
	for(;scanf("%d",&p->data),(ch=getchar())!='\n';){
		
		if(!(*L)){
			
			*L = p;
			(*L)->prior = NULL;
		} 
		else{
			
			q->next = p;
			p->prior = q;
			
		}
		q = p;
		p=(DuLinkedList) malloc (sizeof(DuLNode));
		
	} 
	p->prior=q;
	q->next=p;
	p->next=NULL;
	return SUCCESS;
}
//打印功能选择窗口
void PrintWindows(){
	
	printf("双链表ADT\n");
	printf("A.初始化链表\n");
	printf("B.销毁链表\n");
	printf("C.在指定节点前插入节点\n");
	printf("D.在指定节点后插入节点\n");
	printf("E.删除节点\n");
	printf("F.遍历链表\n");
	printf("请选择功能："); 

}
//暂停和继续（包括吸收一个回车键）
void PauseAndGo()
{
    char EnterKey;
    printf("Enter any key to continue...");
    EnterKey = getchar();
    EnterKey = getchar();
}
