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
	//删除Index 为 Index 的元素
	bool SortSqList(bool order);
	//对列表进行排序(true 升序，false逆序,后续可以追加排序的算法类型)
	int Find(T element);
	//返回第一个为element的元素的Index
};
