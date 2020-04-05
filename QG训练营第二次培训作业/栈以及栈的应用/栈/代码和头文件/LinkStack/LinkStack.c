#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>


//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s){
	
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!(s->top)) return ERROR;
	s->top = NULL;
	s->count = 0; 
	printf("initialized successfully.\n");
	return SUCCESS;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ,¿ÕÔò·µ»ØSUCCESS 
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

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e){
	
	if(isEmptyLStack(s)) return ERROR;
	*e = s->top->data;
	printf("The data of the top is: %d\n",*e);
	return SUCCESS;
}

//Çå¿ÕÕ»
Status clearLStack(LinkStack *s){
	
	LinkStackPtr p = s->top;
	if(isEmptyLStack(s)) return ERROR;
	for(;p->next != NULL;p=p->next){
		
		p->data = 0;
	}
	printf("The stack has been emptied.\n");
	return SUCCESS;
}

//Ïú»ÙÕ»
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

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length){
	
    LinkStackPtr p = s->top;
	if(isEmptyLStack(s)) return ERROR;
    *length = 1;
	for(;p->next;p=p->next)
		
		(*length)++;
	printf("The length of rhe stack is :%d\n",*length);
	return SUCCESS;
}

//ÈëÕ»
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

//³öÕ»,ÅÐ¶ÏÊÇ·ñÎª¿ÕÕ» 
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
