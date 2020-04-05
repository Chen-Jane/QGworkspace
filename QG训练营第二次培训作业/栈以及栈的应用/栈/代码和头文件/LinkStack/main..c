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


//遍历栈 
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

//打印功能选择窗口
void PrintWindows(){
	
	printf("链栈ADT\n");
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

