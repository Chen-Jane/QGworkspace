#include"LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>

int data_size;
void PauseAndGo();
void PrintWindows();
Status DefineDataType(char m);
Status HelpEnLQueue(LQueue *Q);

int main(){
	
	LQueue *p;
	char option,a ;
	void* digit; 
	p = (LQueue*)malloc(sizeof(LQueue));
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
			
			case'A':system("cls");InitLQueue(p);
			                      PauseAndGo();break;
			case'B':system("cls");IsEmptyLQueue(p);TraverseLQueue(p, LPrint);
			                      PauseAndGo();break;
			case'C':system("cls");HelpEnLQueue(p);
			                      TraverseLQueue(p, LPrint);PauseAndGo();break;
			case'D':system("cls");printf("The head data is: %d\n",GetHeadLQueue(p,digit));
			                      TraverseLQueue(p, LPrint);
			                      PauseAndGo();break;
			                      
			case'E':system("cls");DeLQueue(p);TraverseLQueue(p, LPrint);
			                      PauseAndGo();break;
			case'F':system("cls");LengthLQueue(p);TraverseLQueue(p, LPrint);
			                      PauseAndGo();break;                      
			case'G':system("cls");TraverseLQueue(p, LPrint);PauseAndGo();break;
			case'H':system("cls");ClearLQueue(p);TraverseLQueue(p, LPrint);
			                      PauseAndGo();break;
		    case'I':system("cls");DestoryLQueue(p);PauseAndGo();break;                      
            default:system("cls");printf("ERROR!please enter A - I.\n");a = getchar();
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

Status HelpEnLQueue(LQueue *Q){

    printf("Please enter the data you want to add:\n");
	if(strcmp(datatype,"double")==0){
		
		double a ;
		scanf("%lf",&a);
		EnLQueue(Q, &a);
	}
	if(strcmp(datatype,"char")==0){
		
		char a ;
		scanf("%c",&a);
		EnLQueue(Q, &a);
	}		
	if(strcmp(datatype,"int")==0){
		
		int a ;
		scanf("%d",&a); 
		EnLQueue(Q, &a);
	}
	return TRUE;
}

//打印功能选择窗口
void PrintWindows(){
	
	printf("循环队列ADT\n");
	printf("A.初始化队列\n");
	printf("B.判断队列是否为空\n");
	printf("C.入队\n");
	printf("D.得到队头元素\n");
	
	printf("E.出队\n");
	printf("F.检测队列长度\n");
	printf("G.遍历队列\n");
	printf("H.清空队列\n");
	printf("I.销毁队列\n");
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


