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
	printf("请输入一串个数小于栈最大长度的整数并用空格隔开，按回车运行:\n");
	for(;scanf("%d",&digit),(c=getchar())!='\n';){
		
		pushStack(s,digit);
	}
	pushStack(s,digit);
	return SUCCESS;
}

//遍历栈 
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

//打印功能选择窗口
void PrintWindows(){
	
	printf("顺序栈ADT\n");
	printf("A.初始化栈\n");
	printf("B.判断栈是否为空\n");
	printf("C.得到栈顶元素\n");
	printf("D.清空栈\n");
	
	printf("E.销毁栈\n");
	printf("F.检测栈长度\n");
	printf("G.入栈\n");
	printf("H.出栈\n");
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

    /* 创建10个元素的栈，入栈11次，检查软件的容错机制 */
 /*   for (; i<11; i++)
    {
        pushStack(pNewStack, i);
        stackLength(pNewStack, &length);
        printf("pNewStack valid length: %d\n", length);
    }
    /* 入栈10个数据，出栈11次，检查软件的容错机制 */
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
