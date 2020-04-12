#include"AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern data_size;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	
	int i;
	for(i = 0;i<MAXQUEUE;i++){
		
		Q->data[i] = (void*)malloc(sizeof(type));
	}
	Q->length = 0; 
	Q->front = 0;
	Q->rear = 0;
	printf("initialized successfully.\n");
	
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	
	int i;
	for(i = 0;i<MAXQUEUE;i++){
		
		free(Q->data[i]);
	}
	printf("The queue is destroyed.\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	
	if(Q->front == (Q->rear+1)%MAXQUEUE ){
		
		printf("The queue is full.\n");
		return TRUE;
	}else{
		
		printf("The queue is not full.\n");
		return FALSE;
	}

}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	
	return (Q->front == Q->rear ? TRUE : FALSE);
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	
	if(IsEmptyAQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}  
	memcpy(e,Q->data[Q->front],data_size);
	return TRUE;
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	
	if(IsFullAQueue(Q)){
		
		printf("Error:the queue is full.\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear],data,data_size);
	Q->rear = (Q->rear + 1) %  MAXQUEUE;           /*rear后移一位，若在最后则挪至数组头部*/ 
	Q->length++; 
	printf("Enqueue operation succeeded.\n"); 
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	
	if(IsEmptyAQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	Q->front = (Q->front +1) %  MAXQUEUE;          /*front后移一位，若在最后则挪至数组头部*/ 
	Q->length--; 
	printf("Dequeue operation succeeded.\n"); 
	return TRUE;  
}		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	
	if(IsEmptyAQueue(Q)){
		
		printf("Error:the queue is empty.\n");
	}
	Q->front = 0 ;
	Q->rear = 0;
	printf("The queue is emptied.\n");
	return;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	
	if(IsEmptyAQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	int i = Q->front;
	printf("The data of the queue is:\n");
	for(; i!= Q->rear ; i= (i + 1) %  MAXQUEUE){
		
		foo(Q->data[i]);
	}
	printf("\n");
	return TRUE;
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
	
	if(strcmp(datatype,"double")==0)
			printf("%lf ",*(double*)q);
	if(strcmp(datatype,"char")==0)
			printf("%c ",*(char*)q);
	if(strcmp(datatype,"int")==0)
			printf("%d ",*(int*)q);
}	



