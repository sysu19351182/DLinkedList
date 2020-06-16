#pragma once
template<class T>
class Node {
public:
	Node<T>* pred;
	Node<T>* succ;
	T data;
};
