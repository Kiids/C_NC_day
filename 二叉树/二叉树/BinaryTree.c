#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
		return NULL;

	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = a[*pi];
	++(*pi);

	node->_left = BinaryTreeCreate(a, n, pi);
	++(*pi);

	node->_right = BinaryTreeCreate(a, n, pi);

	return node;
}

void _BinaryTreeCreate(BTNode** root, BTDataType* a, int* pi)
{
	*root = (BTNode*)malloc(sizeof(BTNode));
	if (a[*pi] == '#')
	{
		*root = NULL;
		return;
	}
	(*root)->_data = a[*pi];
	++(*pi);
	_BinaryTreeCreate(&(*root)->_left, a, pi);
	++(*pi);
	_BinaryTreeCreate(&(*root)->_right, a, pi);
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free((*root));
	*root = NULL;
}

// 计算二叉树节点数量
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 计算二叉树叶子节点数量
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 计算二叉树第k层节点数量
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* lret = BinaryTreeFind(root->_left, x);
	if (lret != NULL)
		return lret;
	BTNode* rret = BinaryTreeFind(root->_right, x);
	if (rret != NULL)
		return rret;
	return NULL;
}


// 递归遍历
// 前序
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 中序
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// 后序
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 非递归遍历
// 层序遍历
#include "Queue.h"
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);

		if (front->_left != NULL)
			QueuePush(&q, front->_left);
		if (front->_right != NULL)
			QueuePush(&q, front->_right);
	}
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);

	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
			break;
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}
	return true;
}

bool _BinaryTreeComplete(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);

	bool res = true;

	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		for (int i = 0; i < QueueSize(&q); ++i){
			BTNode* front = QueueFront(&q);
			QueuePop(&q);

			if (front->_left == NULL && front->_right != NULL)
			{
				res = false;
				break;
			}
			if (front->_left != NULL)
				QueuePush(&q, front->_left);
			if (front->_right != NULL)
				QueuePush(&q, front->_right);
		}
	}
	return res;
}

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree()
{
	char str[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(str, sizeof(str)/sizeof(char),&i);
	//BTNode* root = NULL;
	//_BinaryTreeCreate(&root, str, &i);
	printf("BinaryTreePrevOrder:");
	BinaryTreePrevOrder(root);
	printf("\n");

	printf("BinaryTreeInOrder:");
	BinaryTreeInOrder(root);
	printf("\n");

	printf("BinaryTreePostOrder:");
	BinaryTreePostOrder(root);
	printf("\n");

	printf("BinaryTreeSize: %d", BinaryTreeSize(root));
	printf("\n");

	printf("BinaryTreeLeafSize: %d", BinaryTreeLeafSize(root));
	printf("\n");

	printf("BinaryTreeLevelKSize: %d", BinaryTreeLevelKSize(root, 2));
	printf("\n");

	printf("BinaryTreeLevelOrder:");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("BinaryTreeComplete: %d", BinaryTreeComplete(root));
	printf("\n");

	char a[] = "ABD##E##CF##G##";
	int j = 0;
	BTNode* completeTree = BinaryTreeCreate(a, sizeof(a) / sizeof(char), &j);
	printf("BinaryTreeComplete: %d", BinaryTreeComplete(completeTree));
	printf("\n");

	printf("_BinaryTreeComplete: %d", _BinaryTreeComplete(root));
	printf("\n");

	printf("_BinaryTreeComplete: %d", _BinaryTreeComplete(completeTree));
	printf("\n");

	BinaryTreeDestory(&root);
}
