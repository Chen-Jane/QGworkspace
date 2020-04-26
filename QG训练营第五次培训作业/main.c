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
			case'B':system("cls");int i,length;printf("请输入一个满二叉树的数据长度：\n");
								  scanf("%d",&length);str = (char*) malloc(sizeof(char)*length);
								  getchar();printf("请输入二叉树数据，未满处用#代替：\n");
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
			case'G':system("cls");BiTree B = NULL;InitBiTree(B);printf("请输入前缀表达式：\n");
								  getchar();ValueCreate(&B);Value(B);printf("result = %d\n",B->data-48);
								  DestroyBiTree(B);PauseAndGo();break;                      
			case'H':system("cls");if(DestroyBiTree(R)) printf("destroyed successfully.\n");
								  PauseAndGo();break;
            default:system("cls");printf("ERROR!please enter A - H.\n");PauseAndGo();
		}	
	} 
	return 0;	
}


//打印功能选择窗口
void PrintWindows(){
	
	printf("二叉链表ADT\n");
	printf("A.初始化二叉树\n");
	printf("B.构造二叉树\n");
	printf("C.先序遍历二叉树\n");
	printf("D.中序遍历二叉树\n");
	
	printf("E.后序遍历二叉树\n");
	printf("F.层序遍历二叉树\n");
	printf("G.前缀表达式二叉树求值\n");
	printf("H.摧毁二叉树\n");
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

