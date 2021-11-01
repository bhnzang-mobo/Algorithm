#define MAX_NODE 10000
#include <malloc.h>
struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = (Node*)malloc(sizeof(Node));
	head->next = nullptr;
	head->prev = nullptr;
}

void addNode2Head(int data)
{
	Node * newnode = getNode(data);
	newnode->prev = head;
	newnode->next = head->next;
	if (head->next) head->next->prev = newnode;
	head->next = newnode;
}

void addNode2Tail(int data)
{
	Node* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	Node * newnode = getNode(data);
	newnode->next = tmp->next;
	newnode->prev = tmp;
	tmp->next = newnode;
}

void addNode2Num(int data, int num)
{
	int idx = 1;
	Node* tmp = head;
	while (tmp->next && idx<num) {
		idx++;
		tmp = tmp->next;
	}
	Node* newnode = getNode(data);
	newnode->prev = tmp;
	newnode->next = tmp->next;
	if(tmp->next) tmp->next->prev = newnode;
	tmp->next = newnode;
	
}

int findNode(int data)
{
	Node * tmp = head;
	int idx = 1;
	while (tmp->next && tmp->next->data != data) {
		idx++;
		tmp = tmp->next;
	}
	if (tmp->next && tmp->next->data == data) {
		return idx;
	}
	return 0;
}

void removeNode(int data)
{
	Node* tmp = head;
	while (tmp->next && tmp->next->data != data) {
		tmp = tmp->next;
	}
	if (tmp->next && tmp->next->data == data) {
		Node * delnode = tmp->next;
		tmp->next = delnode->next;
		if(delnode->next) delnode->next->prev = tmp;
	}
}

int getList(int output[MAX_NODE])
{
	int idx = 0;
	Node* tmp = head;
	while (tmp->next) {
		output[idx++]=tmp->next->data;
		tmp = tmp->next;
	}
	return idx;
}

int getReversedList(int output[MAX_NODE])
{
	Node* tail = head;
	while (tail->next) {
		tail = tail->next;
	}
	int idx = 0;

	while (tail->prev) {
		output[idx++] = tail->data;
		tail = tail->prev;
		
	}
	return idx;
}