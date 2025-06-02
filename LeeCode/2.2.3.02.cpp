#include<iostream>
#include"SqList.h"
using namespace std;

//初始化顺序表
void initSqList(SqList& L) {
	L.length = 0;
	//处理脏数据可以省略
	for (int i = 0; i < sizeof(L.data) / sizeof(L.data[0]);i++) {
		L.data[i] = 0;
	}
}

//插入操作
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i >L.length + 1) return false;
	if (L.length >= MaxSize) return false;
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//输出操作
void PrintList(SqList& L) {
	if (L.length == 0) {
		cout << "List is empty" << endl;
		return;
	}
	for (int i = 0; i < L.length;i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}


void reverseSqList(SqList &L) {
	if (L.length < 2) return;
	//int temp = 0;
	for (int i = 0;i < L.length / 2;i++) {
		/*temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;*/
	
		//使用异或不需要使用中间变量，但是不能交换的值相等
		L.data[i] = L.data[i] ^ L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = L.data[i] ^ L.data[L.length - 1 - i];
		L.data[i] = L.data[i] ^ L.data[L.length - 1 - i];

	}
}

int main() {
	SqList l;
	initSqList(l);
	ListInsert(l, 1, 1);
	ListInsert(l, 2, 2);
	ListInsert(l, 3, 3);
	ListInsert(l, 4, 4);
	ListInsert(l, 5, 5);
	PrintList(l);
	reverseSqList(l);
	PrintList(l);
	return 0;
}