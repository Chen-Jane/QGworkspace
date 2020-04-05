#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void PauseAndGo();
void PrintWindows();
Status CreateStack(SqStack *s);
Status StackTraverse(SqStack *S);

int main(){
	
	SqStack s,*p;
	ElemType a,*m;
	char option ;
	p = &s;
	m = (ElemType*)malloc(sizeof(ElemType));
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");printf("The length of the stack:\n");scanf("%d",&a);
			                      initStack(p,a);CreateStack(p); 
								  StackTraverse(p);break;
			case'B':system("cls");isEmptyStack(p);StackTraverse(p);
			                      PauseAndGo();break;
			case'C':system("cls");getTopStack(p,m);StackTraverse(p);
			                      PauseAndGo();break;
			case'D':system("cls");clearStack(p);StackTraverse(p);
			                      PauseAndGo();break;
			
			case'E':system("cls");destroyStack(p);StackTraverse(p);PauseAndGo();break;
			case'F':system("cls");stackLength(p,m);StackTraverse(p);
			                      PauseAndGo();break;
			case'G':system("cls");printf("The data you want to push : \n");scanf("%d",&a);
			                      pushStack(p,a);StackTraverse(p);
			                      PauseAndGo();break;                      
			case'H':system("cls");popStack(p,m);StackTraverse(p);
			                      PauseAndGo();break;
            defalut:system("cls");printf("ERROR!please enter A - H.\n");PauseAndGo();
		}	
	} 
	return 0;	
}

Status CreateStack(SqStack *s){
	
	char c;
	ElemType digit; 
	printf("������һ������С��ջ��󳤶ȵ��������ÿո���������س�����:\n");
	for(;scanf("%d",&digit),(c=getchar())!='\n';){
		
		pushStack(s,digit);
	}
	pushStack(s,digit);
	return SUCCESS;
}

//����ջ 
Status StackTraverse(SqStack *s){
	
    int i = s->top; 
    if(s == NULL) return ERROR;
    printf("The data of the stack is : \n");
	while(i>=0){
		
		printf("%d ",s->elem[i]);
		i--;
	}
    printf("\n");
    return SUCCESS;
}

//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("˳��ջADT\n");
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
/* 
int main(void)
{
    SqStack  *pNewStack = NULL;
    int length = 0;
 /*   int val = 0;
    int i=0,j=0;
    
    initStack(pNewStack, 10);
    stackLength(pNewStack, &length);
    printf("pNewStack valid length: %d\n", length);

    /* ����10��Ԫ�ص�ջ����ջ11�Σ����������ݴ���� */
 /*   for (; i<11; i++)
    {
        pushStack(pNewStack, i);
        stackLength(pNewStack, &length);
        printf("pNewStack valid length: %d\n", length);
    }
    /* ��ջ10�����ݣ���ջ11�Σ����������ݴ���� */
 /*  for (; j<11; j++)
    {
        getTopStack(pNewStack, &val);
        printf("pNewStack top data: %d\n", val);
        popStack(pNewStack, &val);
        printf("popStack data: %d\n", val);
    }

    isEmptyStack(pNewStack);
	clearStack(pNewStack);
    stackLength(pNewStack, &length);
    printf("pNewStack valid length: %d\n", length);
	destroyStack(pNewStack);
    
    return 0;    
}*/ 
