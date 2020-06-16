
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
	//��ʼ������ 
	void init();
	//����ڵ��������� 
	int size();
	//�пղ���
	bool empty();
	//ɾ������ 
	Node<T> remove(const T& item);
	//�����ס�ĩ�ڵ����
	Node<T> first();
	Node<T> last();
	//ǰ�������� 
	void insertAsFirst(const T& item);
	//��������� 
	void insertAsLast(const T& item);
	//���Ҳ��� 
	Node<T> find(const T& item);
	//�� data ��С������� 
	void sort();
	//����ת���� 
	void reverse();
	//�ϲ���һ����������� 
	void merge(DLinkedList<T>& LIST);
	//������ӡ���ݲ��� 
	void show();
};
#endif
//��������
template<class T>
void DLinkedList<T>::Delete() {
	std::cout << "�ͷſռ�" << std::endl;
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
//��������
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
//��ʼ������ 
template<class T>
void DLinkedList<T>::init() {

	head = new Node<T>();
	tail = new Node<T>();
	head->succ = NULL;
	tail = head;
}

//����ڵ��������� 
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

//�пղ���
template<class T>
bool  DLinkedList<T>::empty() {
	return size() == 0;
}

//ɾ������ 
template<class T>
Node<T>  DLinkedList<T>::remove(const T& item) {
	std::cout << "ɾ������" << item << endl;
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

//�����ס�ĩ�ڵ����
template<class T>
Node<T>  DLinkedList<T>::first() {
	return &head;
}

template<class T>
Node<T>  DLinkedList<T>::last() {
	return &tail;
}

//ǰ���������� 
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
//���Ҳ��� 
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

//�� data ��С������� 
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
//��ת
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
//�ϲ���һ����������� (��list2�������list1)
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
	std::cout << "�ϲ���:" << std::endl;
	this->show();
}
//������ӡ���ݲ��� 
template<class T>
void DLinkedList<T>::show() {
	Node<T>* p = head->succ;
	while (p != NULL) {
		std::cout << p->data << " ";
		p = p->succ;
	}
	std::cout << std::endl;
}
