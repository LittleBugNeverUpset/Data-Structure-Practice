#pragma once
#include<string>
template <typename T>
class SqList {
private:
	T* data;
	int Length;
	int MaxSize;
public:
	SqList();
	void PrintSqList();
	bool ListInsert(T element, int Index);
	bool DeleteElement(int Index);
	//ɾ��Index Ϊ Index ��Ԫ��
	bool SortSqList(bool order);
	//���б��������(true ����false����,��������׷��������㷨����)
	int Find(T element);
	//���ص�һ��Ϊelement��Ԫ�ص�Index
};
