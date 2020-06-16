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
	std::cout << "��ʼ����1��" << std::endl;
	list_1.show();
	std::cout << "�����ȣ�" << list_1.size() << std::endl;
	//list_1.reverse();
	std::cout << "���մ�С����������" << std::endl;
	list_1.sort();
	list_1.remove(5);
	infile.close();
	infile.open("Merge.txt");
	DLinkedList<int> list_2(infile);
	std::cout << "��ʼ����2��" << std::endl;
	list_2.show();
	list_1.merge(list_2);
	list_1.reverse();
	infile.close();
	list_1.Delete();
	list_2.Delete();
	return 0;
}

