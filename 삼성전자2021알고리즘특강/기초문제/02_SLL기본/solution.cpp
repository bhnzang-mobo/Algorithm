#define MAX_NODE2 10000
#include <malloc.h>	

struct Node {
	int data;
	Node* next;
	Node* myAlloc(int _data, Node* next) {
		this->data = _data;
		this->next = next;
		return this;
	}
};

Node node[MAX_NODE2];
int nodeCnt;
Node head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head.next = 0;
}

void addNode2Head(int data)
{
	head.next = node[nodeCnt++].myAlloc(data, head.next);
}

void addNode2Tail(int data)
{
	Node * ptr = &head;
	while (ptr->next) {
		ptr = ptr->next;
	}
	ptr->next = node[nodeCnt++].myAlloc(data, 0);
}

void addNode2Num(int data, int num)
{
	Node* ptr = &head;
	while (num-1) {
		num--;
		ptr = ptr->next;
	}
	ptr->next = node[nodeCnt++].myAlloc(data, ptr->next);
}

void removeNode(int data)
{
	Node * ptr = &head;
	while (ptr->next && ptr->next->data != data) {
		ptr = ptr->next;
	}
	if (ptr->next && ptr->next->data) {
		ptr->next = ptr->next->next;
	}
}

int getList(int output[MAX_NODE2])
{
	Node * ptr = &head;
	int cnt = 0;
	while (ptr->next) {
		output[cnt++] = ptr->next->data;
		ptr = ptr->next;
	}
	return cnt;
}