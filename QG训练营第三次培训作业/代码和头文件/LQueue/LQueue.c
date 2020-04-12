#include"LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern data_size;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		
		printf("Failed to allocate memory.\n");
		return ;
	}
	p->next = NULL;
	Q->front = p ;
	Q->rear = p;
	Q->length = 0;
	printf("initialized successfully.\n");
	return ;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	
	if(IsEmptyLQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return ;
	}
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	printf("The queue is destroyed.\n");
	return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	
	if(IsEmptyLQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	memcpy(e,Q->front->next->data,data_size);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	
	int size;
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		
		printf("Failed to allocate memory.\n");
		return 0;
	}
	p = Q->front;
	for(size = 0;p!=Q->rear;size ++){
		
		p=p->next;
	}
	printf("The length of the queue is : %d\n",size);
	return size;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		
		printf("Failed to allocate memory.\n");
		return FALSE;
	}
	p->data = (void*)malloc(data_size);
	memcpy(p->data,data,data_size);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p ;
	Q->length++;
	printf("Enqueue operation succeeded.\n");
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	
	if(IsEmptyLQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	Q->front->next = Q->front->next->next;
	if(Q->front->next == NULL){
		
		Q->rear = Q->front;
	}
	Q->length--;
	printf("Dequeue operation succeeded.\n"); 
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	
	if(IsEmptyLQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return ;
	}
	Node *p,*q;
	Q->rear = Q->front;
	p=Q->front->next;
	while(p){
		
		q = p;
		p=p->next;
		free(q);
	}
	free(p);
	Q->length = 0;
	printf("The queue is emptied.\n");
	return ;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	
	if(IsEmptyLQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	printf("The data of the queue is:\n");
	for(p=Q->front->next;p;p=p->next){
		
		foo(p->data); 
	}
	printf("\n");
	return TRUE;
	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	
	if(strcmp(datatype,"double")==0)
			printf("%lf ",*(double*)q);
	if(strcmp(datatype,"char")==0)
			printf("%c ",*(char*)q);
	if(strcmp(datatype,"int")==0)
			printf("%d ",*(int*)q);
}
