#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#define NULL 0


//���������˳��ջ
//��ʼ��ջ,top�������±���ͬ 
Status initStack(SqStack *s,int sizes){
	
	s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);
	if(NULL == s->elem){
		
		printf("Failed to apply for memory��\n");
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	printf("Initialize the stack successfully��\n");
	return SUCCESS;
	
}
 
//�ж�ջ�Ƿ�Ϊ��,�����򷵻�SUCCESS�����򷵻�ERROR 
Status isEmptyStack(SqStack *s){
	
	if(s->top == -1){
		
		printf("The stack is empty.\n");
		return SUCCESS;
	}
	else{
		
		printf("The stack is not empty.\n");
	    return ERROR;
	}
}

//�õ�ջ��Ԫ��,���ж�ջ�Ƿ�Ϊ�� 
Status getTopStack(SqStack *s,ElemType *e){
	
	if(s->top == -1){
		
		printf("error:the stack is empty!\n ");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("Get the top element of the stack:%d.\n ",*e);
	return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s){
	
	if(!s){
		
		printf("The point address is not exist.\n");
		return ERROR;
	} 
	s->top = -1;
	s->size = 0;
	printf("The stack has been emptied.\n");
	return SUCCESS;
}

//����ջ,ջ�������򷵻�ERROR 
Status destroyStack(SqStack *s){
	
	if(s->elem){
		
		clearStack(s);
		free(s->elem);
		printf("The stack is destroyed.\n");
		return SUCCESS; 
	}
	return ERROR;	
}

//���ջ���ȣ����ж�ջ�Ƿ����,�������򷵻�ERROR 
Status stackLength(SqStack *s,int *length){
	
	if((s==NULL)||(length==NULL)){
		
		printf("s point NULL or length point NULL.\n");
		return ERROR;
	}
	*length = s->top+1;
	printf("The valid length of the stack is : %d\n",*length);
	return SUCCESS;
}

//��ջ,ջ���򷵻�ERROR 
Status pushStack(SqStack *s,ElemType data){
	
	if(s->top == (s->size-1)){
		
		printf("Error:The stack is full.\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	printf("Successfully pushed into the stack.\n");
	return SUCCESS;
}

//��ջ,��ջΪ���򷵻�ERROR 
Status popStack(SqStack *s,ElemType *data){
	
	if(s->top == -1){
		
		printf("Error:the stack is empty.\n");
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	printf("The deleted data is %d.\n ",*data);
	return SUCCESS; 
} 
