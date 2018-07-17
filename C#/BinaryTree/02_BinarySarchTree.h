#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef int T;


typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	//struct Node *parent;
} Node;


//–аспечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right) {
			printf("(");
			if (root->left) printTree(root->left); else printf("NULL");
			printf(",");
			if (root->right) printTree(root->right); else printf("NULL");
			printf(")");
		}
	}
}

//—оздание нового узла
Node* getFreeNode(T value) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	//tmp->parent = parent;
	return tmp;
}

//¬ставка узла
void insert(Node **head, int value) {
	Node *tmp = NULL;
	//   Node *ins = NULL;
	if (*head == NULL) {
		*head = getFreeNode(value);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (value> tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = getFreeNode(value);
				return;
			}
		}
		else if (value< tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = getFreeNode(value);
				return;
			}
		}
		else {
			exit(2);//дерево построено не правильно
		}
	}
}

void simOrderTravers(Node* root)
{
	if (root) {
		simOrderTravers(root->left);
		printf("%d ", root->data);
		simOrderTravers(root->right);
	}
}

Node* binarySearch(Node* root, int value)
{
	if (root) {
		if (root->data > value)
			binarySearch(root->left, value);
		else if (root->data < value)
			binarySearch(root->right, value);
		else return root;
	}
	else return NULL;
}

void preOrderTravers(Node* root)
{
	if (root) {
		printf("%d ", root->data);
		simOrderTravers(root->left);
		simOrderTravers(root->right);
	}
}

void postOrderTravers(Node* root)
{
	if (root) {
		simOrderTravers(root->left);
		simOrderTravers(root->right);
		printf("%d ", root->data);
	}
}


void binarySearchTree()
{
	Node *Tree = NULL;
	int el = 0;
	//работаем с текстовым файлом
	FILE* file = fopen("C:\\GAMES\\GB\\HW_L9\\HW_L9\\HW_L9\\text.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count);//—читываем количество записей
	int i;
	for (i = 0; i<count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\nSimOrderTravers:");
	simOrderTravers(Tree);
	printf("\nPreOrderTravers:");
	preOrderTravers(Tree);
	printf("\nPostOrderTravers:");
	postOrderTravers(Tree);
	printf("\n");
	printf("type an element for searching: \n");
	scanf("%d", &el);	
	_flushall();
	if (binarySearch(Tree, el) != NULL) 
		if (binarySearch(Tree, el)->data == el)
			printf("element found!\n");
		else
			printf("element not found!\n");
	else printf("element not found!\n");
	getchar();
}
