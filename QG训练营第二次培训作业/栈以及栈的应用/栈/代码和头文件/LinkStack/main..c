#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>


void PauseAndGo();
void PrintWindows();
Status TraverseLStack(LinkStack *s);

int main(){
	
	LinkStack p,*ps;
	ElemType a,*e;
	char option ;
	ps = &p;
	e = (ElemType*)malloc(sizeof(ElemType));
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");initLStack(ps);PauseAndGo();break;
			case'B':system("cls");isEmptyLStack(ps);PauseAndGo();break;
			case'C':system("cls");getTopLStack(ps,e);PauseAndGo();break;
			case'D':system("cls");clearLStack(ps);PauseAndGo();break;
			
			case'E':system("cls");destroyLStack(ps);PauseAndGo();break;
			case'F':system("cls");LStackLength(ps,e);PauseAndGo();break;
			case'G':system("cls");printf("The data you want to push:\n");scanf("%d",&a);
			                      pushLStack(ps,a);TraverseLStack(ps);
			                      PauseAndGo();break;                      
			case'H':system("cls");popLStack(ps,e);TraverseLStack(ps);
			                      PauseAndGo();break;
            default:printf("ERROR!please enter A - H.\n");PauseAndGo();
		}	
	} 
	return 0;	
}


//����ջ 
Status TraverseLStack(LinkStack *s){
	
	int i = s->count;
	LinkStackPtr p = s->top;
    if(isEmptyLStack(s)) return ERROR;
	printf("The data of the stack is :\n");
	for(;i>0;i--){
		
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return SUCCESS;
}

//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("��ջADT\n");
	printf("A.��ʼ��ջ\n");
	printf("B.�ж�ջ�Ƿ�Ϊ��\n");
	printf("C.�õ�ջ��Ԫ��\n");
	printf("D.���ջ\n");
	
	printf("E.����ջ\n");
	printf("F.���ջ����\n");
	printf("G.��ջ\n");
	printf("H.��ջ\n");
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

