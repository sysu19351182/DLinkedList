#include"DLinkedList.h"
#include"Node.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream infile;
	infile.open("IntegerData.txt");
	DLinkedList<int> list_1(infile);
	std::cout << "初始链表1：" << std::endl;
	list_1.show();
	std::cout << "链表长度：" << list_1.size() << std::endl;
	//list_1.reverse();
	std::cout << "按照大小排序后的链表：" << std::endl;
	list_1.sort();
	list_1.remove(5);
	infile.close();
	infile.open("Merge.txt");
	DLinkedList<int> list_2(infile);
	std::cout << "初始链表2：" << std::endl;
	list_2.show();
	list_1.merge(list_2);
	list_1.reverse();
	infile.close();
	list_1.Delete();
	list_2.Delete();
	return 0;
}

