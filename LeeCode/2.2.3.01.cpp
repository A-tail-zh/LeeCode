#include<iostream>
#include"SqList.h"
using namespace std;

//��ʼ��˳���
void initSqList(SqList& L) {
	L.length = 0;
	//���������ݿ���ʡ��
	for (int i = 0; i < sizeof(L.data) / sizeof(L.data[0]);i++) {
		L.data[i] = 0;
	}
}

//�������
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

//�������
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


int deleteMinElem(SqList &L) {
	if (L.length == 0) {
		cout << "˳���Ϊ��" << endl;
		return 0;
	}

	int MinIndex = 0;
	int Min = 0;
	for (int i = 1; i < L.length;i++) {
		if (L.data[MinIndex] > L.data[i])
			MinIndex = i;
	}
	Min = L.data[MinIndex];
	L.data[MinIndex] = L.data[L.length - 1];
	L.length--;
	return Min;
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
	cout << "ɾ��Ԫ����:" << deleteMinElem(l) << endl;
	PrintList(l);
	cout << l.length;
	return 0;
}