#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

void PauseAndGo();
void PrintWindows();

int main(){
	
	BiTree R = NULL;
	char option ;
	char *str = &option;
	while(1){
		
		PrintWindows();
		switch(option = getchar()){
			
			case'A':system("cls");if(InitBiTree(R)) printf("initialized successfully.\n");
								  PauseAndGo();break;
			case'B':system("cls");int i,length;printf("������һ���������������ݳ��ȣ�\n");
								  scanf("%d",&length);str = (char*) malloc(sizeof(char)*length);
								  getchar();printf("��������������ݣ�δ������#���棺\n");
								  for(i=0;i<length;i++) *(str + i)=getchar();
								  if(CreateBiTree(&R, str)) printf("Create successfully.\n");
								  PauseAndGo();break;
			case'C':system("cls");PreOrderTraverse(R,visit);printf("\n");
								  PauseAndGo();break;
			case'D':system("cls");InOrderTraverse(R,visit);printf("\n");
								  PauseAndGo();break;
								  
			case'E':system("cls");PostOrderTraverse(R,visit);printf("\n");
								  PauseAndGo();break;
			case'F':system("cls");LevelOrderTraverse(R,visit);printf("\n");
								  PauseAndGo();break;
			case'G':system("cls");BiTree B = NULL;InitBiTree(B);printf("������ǰ׺���ʽ��\n");
								  getchar();ValueCreate(&B);Value(B);printf("result = %d\n",B->data-48);
								  DestroyBiTree(B);PauseAndGo();break;                      
			case'H':system("cls");if(DestroyBiTree(R)) printf("destroyed successfully.\n");
								  PauseAndGo();break;
            default:system("cls");printf("ERROR!please enter A - H.\n");PauseAndGo();
		}	
	} 
	return 0;	
}


//��ӡ����ѡ�񴰿�
void PrintWindows(){
	
	printf("��������ADT\n");
	printf("A.��ʼ��������\n");
	printf("B.���������\n");
	printf("C.�������������\n");
	printf("D.�������������\n");
	
	printf("E.�������������\n");
	printf("F.�������������\n");
	printf("G.ǰ׺���ʽ��������ֵ\n");
	printf("H.�ݻٶ�����\n");
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

