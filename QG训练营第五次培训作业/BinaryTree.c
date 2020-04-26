#include "BinaryTree.h"
extern i;

/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree T){
	
	T = NULL;
	return SUCCESS;
}

/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree T){
	
	if(!T){
		
		printf("Tree does not exist.\n");
		return ERROR;
	}
	if(T->lchild) 				//���Ӵ��������������� 
		DestroyBiTree(T->lchild);
	if(T->rchild)				//�Һ��Ӵ��������Һ������� 
		DestroyBiTree(T->rchild);
	free(T);
	T = NULL;
	return SUCCESS; 
}

/**
 *  @name        : Status CreateBiTree(BiTree *T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
static int j=0; 
Status CreateBiTree(BiTree *T, char* definition){
		
	TElemType ch ;
	if(j<strlen(definition)) ch = *(definition + j++);
	else return SUCCESS;
	if(ch == '#')
		*T = NULL;
	else{
		
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T){
			
			printf("Failed to allocate memory.\n");
			
		}
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild),definition);
		CreateBiTree(&((*T)->rchild),definition);	
	}
} 

Status visit(TElemType e){
	
	printf("%c ",e);
	return SUCCESS;
}

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(!T){
		
		return ERROR;
	}
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit);
	return SUCCESS;	
}

/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(!T){
		
		return ERROR;
	}
	InOrderTraverse(T->lchild,visit);
	visit(T->data);
	InOrderTraverse(T->rchild,visit);
	return SUCCESS;	
}	

/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(!T){
		
		return ERROR;
	}
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	visit(T->data);
	return SUCCESS;	
}

//��α���׼����������ز��� 
Status InitLQueue(LQueue* Q){
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	Q->front = p;
	Q->rear = p;
	Q->front->next = NULL;
	return SUCCESS;
} 

Status IsEmptyLQueue(LQueue* Q){
	
	return (Q->front == Q->rear ? SUCCESS : ERROR);
}

Status EnLQueue(LQueue* Q,BiTree a){
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = a;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return SUCCESS;
}

Status DeLQueue(LQueue* Q){
	Node *p;
	if(IsEmptyLQueue(Q)) return ERROR;
	p = Q->front->next;
	Q->front->next = p->next;
	if(p->next == NULL)
		Q->rear = Q->front;
	free(p);
	return SUCCESS;
}

BiTree GetHead(LQueue* Q){
	BiTNode* q ;
	Node* p;
	if(IsEmptyLQueue(Q)) return q;
	else{
		p = Q->front->next;
		return p->data;
	}
}

/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(!T){
		
		printf("Tree does not exist.\n");
		return ERROR;
	}
	LQueue Q;
	BiTree p;
	InitLQueue(&Q);
	EnLQueue(&Q,T);
	while(!IsEmptyLQueue(&Q)){
		
		p = GetHead(&Q);
		DeLQueue(&Q);
		visit(p->data);
		if(p->lchild){
			
			EnLQueue(&Q,p->lchild);
		}
		if(p->rchild){
			
			EnLQueue(&Q,p->rchild);
		}
	}
	return SUCCESS;
}

/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T){
	
	if(!T){
		
		printf("Tree does not exist.\n");
		return 0;
	}
	if(T->Tag==1){
		
		if((T->lchild->Tag) != 0)
			Value(T->lchild);
		if(T->rchild->Tag != 0)
			Value(T->rchild);
		if( ((T->lchild->Tag) == 0) && ((T->rchild->Tag) == 0) ){
			
			switch(T->data){
					
				case'+':T->data = T->lchild->data + T->rchild->data - 48;break;
				case'-':T->data = T->lchild->data - T->rchild->data + 48;break;
				case'*':T->data = (T->lchild->data - 48) * (T->rchild->data - 48) + 48;break;
				case'/':T->data = (T->lchild->data - 48) / (T->rchild->data - 48) + 48;break;
				default:printf("enter fata error.\n");
			}
			T->Tag = 0;
			return 1;		
		}
	} 
	return 1;
}		
	
Status ValueCreate(BiTree *T){
	TElemType ch;
	ch = getchar();
	if(ch != '\n'){
		
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T){
			
			printf("Failed to allocate memory.\n");
			return ERROR;
		}
		(*T)->data = ch;
		if((ch<=57)&&(ch>=48)){
			(*T)->Tag=0;
			(*T)->lchild = (*T)->rchild = NULL;
		}else if((ch=='*')||(ch=='/')||(ch=='+')||(ch=='-')){
			(*T)->Tag=1;
			ValueCreate(&((*T)->lchild));
			ValueCreate(&((*T)->rchild));
		}else{
			printf("enter data error.\n");
			return ERROR;
		}
	}
	return SUCCESS;
}
