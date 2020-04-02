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
		                          printf("��������Ҫ����λ�ú�Ľڵ�ֵ��");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("������Ҫ����Ľڵ��ֵ��");scanf("%d",&qdata);qnode->data = qdata;
								  InsertBeforeList_DuL(pnode, qnode); TraverseList_DuL(head, visit);PauseAndGo(); break;         
			case'D':system("cls");{ElemType pdata,qdata;DuLNode* pnode; DuLNode* qnode = (DuLinkedList)malloc(sizeof(DuLNode));
			                      if (qnode == NULL) { printf("Error : malloc faile in case 'D'.\n"); PauseAndGo(); break; }
		                          printf("��������Ҫ����λ��ǰ�Ľڵ�ֵ��");scanf("%d",&pdata);
		                          pnode = FindNode(head, pdata);
								  printf("������Ҫ����Ľڵ��ֵ��");scanf("%d",&qdata);qnode->data = qdata; 
								  InsertAfterList_DuL(pnode, qnode);TraverseList_DuL(head, visit);} PauseAndGo(); break;     					  
		    case'E':system("cls");ElemType a; printf("������Ҫɾ���Ľڵ��ǰһ�����洢��ֵ �� "); scanf("%d", &a);
                                  DuLNode* b;b = FindNode(head, a);
                                  DeleteList_DuL(b, &deletedata);TraverseList_DuL(head, visit);PauseAndGo();break;
		    case'F':system("cls");TraverseList_DuL(head, visit);PauseAndGo();break;
		    default: return 0;
		}
	} 
} 
//����˫���� 
Status CreateList(DuLinkedList* L){
	
	char ch;
	DuLNode*p=NULL,*q=NULL;
	*L = NULL;
	p=(DuLinkedList) malloc (sizeof(DuLNode));
	//if(p==NULL) return ERROR;
	printf("������һ���������ÿո���������س�����:\n");
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
//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("˫����ADT\n");
	printf("A.��ʼ������\n");
	printf("B.��������\n");
	printf("C.��ָ���ڵ�ǰ����ڵ�\n");
	printf("D.��ָ���ڵ�����ڵ�\n");
	printf("E.ɾ���ڵ�\n");
	printf("F.��������\n");
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
