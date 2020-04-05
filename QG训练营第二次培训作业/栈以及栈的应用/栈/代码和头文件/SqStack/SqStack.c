#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#define NULL 0


//基于数组的顺序栈
//初始化栈,top与数组下标相同 
Status initStack(SqStack *s,int sizes){
	
	s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);
	if(NULL == s->elem){
		
		printf("Failed to apply for memory！\n");
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	printf("Initialize the stack successfully！\n");
	return SUCCESS;
	
}
 
//判断栈是否为空,若空则返回SUCCESS，否则返回ERROR 
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

//得到栈顶元素,先判断栈是否为空 
Status getTopStack(SqStack *s,ElemType *e){
	
	if(s->top == -1){
		
		printf("error:the stack is empty!\n ");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("Get the top element of the stack:%d.\n ",*e);
	return SUCCESS;
}

//清空栈
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

//销毁栈,栈不存在则返回ERROR 
Status destroyStack(SqStack *s){
	
	if(s->elem){
		
		clearStack(s);
		free(s->elem);
		printf("The stack is destroyed.\n");
		return SUCCESS; 
	}
	return ERROR;	
}

//检测栈长度，先判断栈是否存在,不存在则返回ERROR 
Status stackLength(SqStack *s,int *length){
	
	if((s==NULL)||(length==NULL)){
		
		printf("s point NULL or length point NULL.\n");
		return ERROR;
	}
	*length = s->top+1;
	printf("The valid length of the stack is : %d\n",*length);
	return SUCCESS;
}

//入栈,栈满则返回ERROR 
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

//出栈,若栈为空则返回ERROR 
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
