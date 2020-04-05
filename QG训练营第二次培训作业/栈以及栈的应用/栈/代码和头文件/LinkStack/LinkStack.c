#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>


//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!(s->top)) return ERROR;
	s->top = NULL;
	s->count = 0; 
	printf("initialized successfully.\n");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��,���򷵻�SUCCESS 
Status isEmptyLStack(LinkStack *s){
	
	if(s->top == NULL){
		
		printf("The stack is empty\n");
		return SUCCESS;	
	}
	else{
		
		printf("The stack is not empty\n");
		return ERROR;
	}  
	
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	
	if(isEmptyLStack(s)) return ERROR;
	*e = s->top->data;
	printf("The data of the top is: %d\n",*e);
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	
	LinkStackPtr p = s->top;
	if(isEmptyLStack(s)) return ERROR;
	for(;p->next != NULL;p=p->next){
		
		p->data = 0;
	}
	printf("The stack has been emptied.\n");
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	
	int i = s->count;
	LinkStackPtr q,p=NULL;
	if(isEmptyLStack(s)) return ERROR;
	p = s->top;
	for(;i>0;i--){
		
		q = p->next;
		free(p);
		p = q;
	}
	s->count = 0;
	printf("The stack is destroyed.\n");
	return SUCCESS;
	
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	
    LinkStackPtr p = s->top;
	if(isEmptyLStack(s)) return ERROR;
    *length = 1;
	for(;p->next;p=p->next)
		
		(*length)++;
	printf("The length of rhe stack is :%d\n",*length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!p){
		
		printf("Failed to apply for memory!\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	printf("successfully push.\n");
	return SUCCESS;
}

//��ջ,�ж��Ƿ�Ϊ��ջ 
Status popLStack(LinkStack *s,ElemType *data){
	
	LinkStackPtr p = s->top;
	if(isEmptyLStack(s)) return ERROR;
	*data = p->data; 
	s->top = p->next; 
	s->count--;
	free(p);
	printf("successfully popped.\n");
	return SUCCESS;
} 
