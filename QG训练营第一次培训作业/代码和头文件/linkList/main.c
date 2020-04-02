#include "linkedList.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void visit(ElemType e);
void PrintWindows();
void PauseAndGo();
Status CreateList(LinkedList* L);

int main(){
	
	LinkedList head = NULL;
	LinkedList head2= NULL; 
	ElemType deletedata;
	char option;
	CreateList(&head); 
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");InitList(&head2);PauseAndGo();break;
			case'B':system("cls");DestroyList(&head);PauseAndGo();break;
			case'C':system("cls");ElemType pdata,qdata;LNode* pnode; LNode* qnode = malloc(sizeof(LNode)); 
			                      if (qnode == NULL) { printf("Error : malloc faile in case 'C'.\n"); PauseAndGo(); break; }
		                          printf("请输入所要插入位置前的节点值：");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("请输入要插入的节点的值：");scanf("%d",&qdata);qnode->data = qdata;
								  InsertList(pnode, qnode);TraverseList(head, visit);PauseAndGo();break;         
		    case'D':system("cls");ElemType a; printf("输入想要删除的节点的前一个结点存储的值 ： "); scanf("%d", &a);
                                  LNode* b = FindNode(head, a);
                                  DeleteList(b, &deletedata);TraverseList(head, visit);PauseAndGo();break;
		    case'E':system("cls");TraverseList(head, visit);PauseAndGo();break;
		
		    case'F':system("cls");int num;
		                          printf("输入想要查找的值：\n"); 
		                          scanf("%d",&num);
		                          SearchList(head,num);PauseAndGo();break;
		    case'G':system("cls");ReverseList(&head);TraverseList(head, visit);PauseAndGo();break;
		    case'H':system("cls");IsLoopList(head);PauseAndGo();break;
		    case'I':system("cls");FindMidNode(&head);PauseAndGo();break;
		    default: return 0;
		}
	} 
}	
//使用尾插法创建链表 
Status CreateList(LinkedList* L){
	
	char ch;
	LNode*node,*end;
	*L=(LinkedList) malloc (sizeof(LNode));
	node=(LinkedList) malloc (sizeof(LNode));
	if(!node||!(*L)) return ERROR;
	(*L)->next = NULL;
	end = *L;
	printf("请输入一串整数并用空格隔开，按回车运行:\n");
	for(;scanf("%d",&node->data),(ch=getchar())!='\n';){
		
		end->next=node; 
		end=node;
		node=(LinkedList) malloc (sizeof(LNode)); 
	    if(!node) return ERROR;
		
	} 
	end->next = node;
	node->next = NULL;
	return SUCCESS;
}
//打印功能选择窗口
void PrintWindows(){
	
	printf("单链表ADT\n");
	printf("A.初始化链表\n");
	printf("B.销毁链表\n");
	printf("C.插入节点\n");
	printf("D.删除节点\n");
	printf("E.遍历链表\n");
	
	printf("F.查找节点\n");
	printf("G.反转链表\n");
	printf("H.判断链表是否成环\n");
	printf("I.查找链表中间节点\n");
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
