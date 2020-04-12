#include"LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern data_size;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
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
