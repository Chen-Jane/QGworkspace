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
		                          printf("��������Ҫ����λ��ǰ�Ľڵ�ֵ��");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("������Ҫ����Ľڵ��ֵ��");scanf("%d",&qdata);qnode->data = qdata;
								  InsertList(pnode, qnode);TraverseList(head, visit);PauseAndGo();break;         
		    case'D':system("cls");ElemType a; printf("������Ҫɾ���Ľڵ��ǰһ�����洢��ֵ �� "); scanf("%d", &a);
                                  LNode* b = FindNode(head, a);
                                  DeleteList(b, &deletedata);TraverseList(head, visit);PauseAndGo();break;
		    case'E':system("cls");TraverseList(head, visit);PauseAndGo();break;
		
		    case'F':system("cls");int num;
		                          printf("������Ҫ���ҵ�ֵ��\n"); 
		                          scanf("%d",&num);
		                          SearchList(head,num);PauseAndGo();break;
		    case'G':system("cls");ReverseList(&head);TraverseList(head, visit);PauseAndGo();break;
		    case'H':system("cls");IsLoopList(head);PauseAndGo();break;
		    case'I':system("cls");FindMidNode(&head);PauseAndGo();break;
		    default: return 0;
		}
	} 
}	
//ʹ��β�巨�������� 
Status CreateList(LinkedList* L){
	
	char ch;
	LNode*node,*end;
	*L=(LinkedList) malloc (sizeof(LNode));
	node=(LinkedList) malloc (sizeof(LNode));
	if(!node||!(*L)) return ERROR;
	(*L)->next = NULL;
	end = *L;
	printf("������һ���������ÿո���������س�����:\n");
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
//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("������ADT\n");
	printf("A.��ʼ������\n");
	printf("B.��������\n");
	printf("C.����ڵ�\n");
	printf("D.ɾ���ڵ�\n");
	printf("E.��������\n");
	
	printf("F.���ҽڵ�\n");
	printf("G.��ת����\n");
	printf("H.�ж������Ƿ�ɻ�\n");
	printf("I.���������м�ڵ�\n");
	printf("��ѡ���ܣ�"); 

}
//��ͣ�ͼ�������������һ���س�����
void PauseAndGo()
{
    char EnterKey;
    printf("Enter any key to continue...");
    EnterKey = getchar();
    EnterKey = getchar();
}
