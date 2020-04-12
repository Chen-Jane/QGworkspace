#include"AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern data_size;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	
	return (Q->front == Q->rear ? TRUE : FALSE);
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	
	if(IsFullAQueue(Q)){
		
		printf("Error:the queue is full.\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear],data,data_size);
	Q->rear = (Q->rear + 1) %  MAXQUEUE;           /*rear����һλ�����������Ų������ͷ��*/ 
	Q->length++; 
	printf("Enqueue operation succeeded.\n"); 
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	
	if(IsEmptyAQueue(Q)){
		
		printf("Error:the queue is empty.\n");
		return FALSE;
	}
	Q->front = (Q->front +1) %  MAXQUEUE;          /*front����һλ�����������Ų������ͷ��*/ 
	Q->length--; 
	printf("Dequeue operation succeeded.\n"); 
	return TRUE;  
}		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
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



