#include<iostream>
#include "SqList.h"

using namespace std;

//初始化顺序表
void initSqList(SqList &L) {
	L.length = 0;
	//处理脏数据可以省略
	for (int i = 0; i < sizeof(L.data) / sizeof(L.data[0]);i++) {
		L.data[i] = 0;
	}
}

//求表长
int getSqListLength(SqList &L) {
	return L.length;
}

//按值查找
int LocateElem(SqList &L,int e) {
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] == e) return i + 1;
	}
	return 0;
}

//按位查找
int GetElem(SqList& L, int i) {
	if (i < 1 || i> L.length) return 0;
	return L.data[i - 1];
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
//删除操作
bool ListDelete(SqList& L,int i,int & e) {
	if (i< 1 || i>L.length) return false;
	e = L.data[i - 1];
	for (int j = i - 1;j < L.length - 1;j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;
	return true;
}

//输出操作
void PrintList(SqList& L) {
	if (L.length == 0) {
		cout << "List is empty" << endl;
		return;
	}
	for (int i = 0; i < L.length;i++) {
		cout << L.data[i] << " " ;
	}
	cout << endl;
}

//判空操作
bool Empty(SqList &L) {
	return L.length == 0;
}

//销毁操作
void DestoryList(SqList &L) {
	L.length = 0;
	//静态分配系统自动回收内存
}

int main() {
	SqList l;
	int e = 0;
	initSqList(l);
	PrintList(l);
	cout << Empty(l) << endl;
	ListInsert(l, 1, 1);
	ListInsert(l, 2, 2);
	ListInsert(l, 3, 3);
	ListDelete(l, 2, e);
	cout << e <<"删除e的值是: "<< endl;

	PrintList(l);

	return 0;
}