
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include<iostream>
#include <fstream>
#include <string>
#include"Node.h"
using namespace std;

template<class T>
class DLinkedList {
public:
	Node<T>* head;
	Node<T>* tail;
	DLinkedList(ifstream& is);
	void Delete();
	//初始化操作 
	void init();
	//报告节点总数操作 
	int size();
	//判空操作
	bool empty();
	//删除操作 
	Node<T> remove(const T& item);
	//返回首、末节点操作
	Node<T> first();
	Node<T> last();
	//前向插入操作 
	void insertAsFirst(const T& item);
	//向后插入操作 
	void insertAsLast(const T& item);
	//查找操作 
	Node<T> find(const T& item);
	//按 data 大小排序操作 
	void sort();
	//链表反转操作 
	void reverse();
	//合并另一有序链表操作 
	void merge(DLinkedList<T>& LIST);
	//遍历打印数据操作 
	void show();
};
#endif
//析构函数
template<class T>
void DLinkedList<T>::Delete() {
	std::cout << "释放空间" << std::endl;
	Node<T>* q;
	Node<T>* p = head->succ;
	while (p != NULL)
	{
		q = p;
		p = p->succ;
		delete q;
	}
	p = NULL;
	q = NULL;
}
//构造链表
template<class T>
DLinkedList<T>::DLinkedList(ifstream& is) {
	init();
	string text;
	while (getline(is, text))
	{
		if (text.at(0) == 'd')
		{
			string num2(text, text.find_first_of(':') + 1, text.find_first_of(' ') - text.find_first_of(':'));
			int b = std::stoi(num2);
			Node<T>* temp = new Node<T>();
			temp->data = b;
			temp->succ = NULL;
			temp->pred = tail;
			tail->succ = temp;
			tail = temp;
		}
	}
}
//初始化操作 
template<class T>
void DLinkedList<T>::init() {

	head = new Node<T>();
	tail = new Node<T>();
	head->succ = NULL;
	tail = head;
}

//报告节点总数操作 
template<class T>
int DLinkedList<T>::size() {
	Node<T>* p;
	p = head;
	int size = -1;
	while (p != NULL)
	{
		size++;
		p = p->succ;
	}
	return size;
}

//判空操作
template<class T>
bool  DLinkedList<T>::empty() {
	return size() == 0;
}

//删除操作 
template<class T>
Node<T>  DLinkedList<T>::remove(const T& item) {
	std::cout << "删除数据" << item << endl;
	Node<T>* p = &find(item);
	Node<T>* m = new Node<T>();
	m = p->pred;
	Node<T>* n = new Node<T>();
	n = p->succ;
	m->succ = p->succ;
	n->pred = p->pred;
	show();
	return *m;
}

//返回首、末节点操作
template<class T>
Node<T>  DLinkedList<T>::first() {
	return &head;
}

template<class T>
Node<T>  DLinkedList<T>::last() {
	return &tail;
}

//前后向插入操作 
template<class T>
void  DLinkedList<T>::insertAsFirst(const T& item) {
	Node<T>* Q = new Node<T>();
	Q->data = item;
	Q->pred = NULL;
	Q->succ = head;
	head->pred = Q;
	head = Q;
}
template<class T>
void  DLinkedList<T>::insertAsLast(const T& item) {
	Node<T>* Q = new Node<T>();
	Q->data = item;
	Q->succ = NULL;
	Q->pred = tail;
	tail->succ = Q;
	tail = Q;
}
//查找操作 
template<class T>
Node<T>  DLinkedList<T>::find(const T& item) {
	Node<T>* p = new Node<T>();
	p = head->succ;
	while (p != NULL)
	{
		if (p->data == item)
		{
			return *p;
		}
		else
			p = p->succ;
	}
}

//按 data 大小排序操作 
template<class T>
void  DLinkedList<T>::sort() {
	Node<T>* p = new Node<T>();
	Node<T>* q = new Node<T>();
	T temp;
	for (p = head->succ; p->succ != NULL; p = p->succ)
	{
		for (q = p->succ; q != NULL; q = q->succ)
		{
			if (q->data < p->data)
			{
				temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
		}
	}
	show();
}
//反转
template<class T>
void  DLinkedList<T>::reverse() {
		Node<T>* pre = NULL;
		Node<T>* next = NULL;
		Node<T>* current = head->succ;
		while (current != NULL) {
			next = current->succ;
			current->succ = pre;
			if (next == NULL) {
				head->succ = current;
				current->pred = head;
				break;
			}
			pre = current;
			current->pred = next;
			current = next;
		}
		show();
}
//合并另一有序链表操作 (将list2后向插入list1)
template<class T>
void  DLinkedList<T>::merge(DLinkedList<T>& LIST) {
	int N = LIST.size();
	Node<T>* m = new Node<T>();
	m = LIST.head->succ;
	for (int i = 0;i < N;i++)
	{
		this->insertAsLast(m->data);
		m = m->succ;
	}
	std::cout << "合并后:" << std::endl;
	this->show();
}
//遍历打印数据操作 
template<class T>
void DLinkedList<T>::show() {
	Node<T>* p = head->succ;
	while (p != NULL) {
		std::cout << p->data << " ";
		p = p->succ;
	}
	std::cout << std::endl;
}
