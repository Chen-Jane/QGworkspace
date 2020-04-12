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
	printf("��ѡ���������ͣ�1.����  2.�ַ��� 3.������\n");
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

//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("ѭ������ADT\n");
	printf("A.��ʼ������\n");
	printf("B.�ж϶����Ƿ�Ϊ��\n");
	printf("C.���\n");
	printf("D.�õ���ͷԪ��\n");
	
	printf("E.����\n");
	printf("F.�����г���\n");
	printf("G.��������\n");
	printf("H.��ն���\n");
	printf("I.���ٶ���\n");
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


