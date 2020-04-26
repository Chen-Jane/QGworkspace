#include "BinaryTree.h"
extern i;

/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree T){
	
	T = NULL;
	return SUCCESS;
}

/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
 */
Status DestroyBiTree(BiTree T){
	
	if(!T){
		
		printf("Tree does not exist.\n");
		return ERROR;
	}
	if(T->lchild) 				//左孩子存在销毁左孩子子树 
		DestroyBiTree(T->lchild);
	if(T->rchild)				//右孩子存在销毁右孩子子树 
		DestroyBiTree(T->rchild);
	free(T);
	T = NULL;
	return SUCCESS; 
}

/**
 *  @name        : Status CreateBiTree(BiTree *T, char* definition);
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
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
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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

//层次遍历准备：队列相关操作 
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
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
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
