#include"AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>

int data_size;
void PauseAndGo();
void PrintWindows();
Status DefineDataType(char m);
Status HelpEnAQueue(AQueue *Q);

int main(){
	
	AQueue *p;
	char option,a ;
	void* digit; 
	p = (AQueue*)malloc(sizeof(AQueue));
	printf("请选择数据类型：1.整型  2.字符型 3.浮点型\n");
	scanf("%c",&a);
	DefineDataType(a);
	if(strcmp(datatype,"double")==0)
			digit=(double*)malloc(sizeof(double)); 
	if(strcmp(datatype,"char")==0)
			digit=(char*)malloc(sizeof(char));
	if(strcmp(datatype,"int")==0)
			digit=(int*)malloc(sizeof(int));
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");InitAQueue(p);
			                      PauseAndGo();break;
			case'B':system("cls");IsEmptyAQueue(p);TraverseAQueue(p, APrint);
			                      PauseAndGo();break;
			case'C':system("cls");IsFullAQueue(p);TraverseAQueue(p, APrint);
			                      PauseAndGo();break;
			case'D':system("cls");HelpEnAQueue(p);
			                      TraverseAQueue(p, APrint);PauseAndGo();break;
			case'E':system("cls");printf("The head data is: %d\n",GetHeadAQueue(p,digit));
			                      TraverseAQueue(p, APrint);
			                      PauseAndGo();break;
			                      
			case'F':system("cls");DeAQueue(p);TraverseAQueue(p, APrint);
			                      PauseAndGo();break;
			case'G':system("cls");printf("The length of the queue is: %d\n",LengthAQueue(p));
			                      TraverseAQueue(p, APrint);PauseAndGo();break;                      
			case'H':system("cls");TraverseAQueue(p, APrint);PauseAndGo();break;
			case'I':system("cls");ClearAQueue(p);TraverseAQueue(p, APrint);
			                      PauseAndGo();break;
		    case'J':system("cls");DestoryAQueue(p);PauseAndGo();break;                      
            default:system("cls");printf("ERROR!please enter A - J.\n");a = getchar();
		}	
	} 
	return 0;	
}
Status DefineDataType(char m){
	
	switch(m){
		
		case'1':strcpy(datatype,"int");
		        data_size = sizeof(int);break;
		case'2':strcpy(datatype,"char");
		        data_size = sizeof(char);break;
		case'3':strcpy(datatype,"double");
		        data_size = sizeof(double);break;
		default:printf("ERROR!please enter 1-3.\n");
	}
	PauseAndGo();
	return TRUE;
}

Status HelpEnAQueue(AQueue *Q){

    printf("Please enter the data you want to add:\n");
	if(strcmp(datatype,"double")==0){
		
		double a ;
		scanf("%lf",&a);
		EnAQueue(Q, &a);
	}
	if(strcmp(datatype,"char")==0){
		
		char a ;
		scanf("%c",&a);
		EnAQueue(Q, &a);
	}		
	if(strcmp(datatype,"int")==0){
		
		int a ;
		scanf("%d",&a); 
		EnAQueue(Q, &a);
	}
	return TRUE;
}

//打印功能选择窗口
void PrintWindows(){
	
	printf("循环队列ADT\n");
	printf("A.初始化队列\n");
	printf("B.判断队列是否为空\n");
	printf("C.判断队列是否为满\n");
	printf("D.入队\n");
	printf("E.得到队头元素\n");
	
	printf("F.出队\n");
	printf("G.检测队列长度\n");
	printf("H.遍历队列\n");
	printf("I.清空队列\n");
	printf("J.销毁队列\n");
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


