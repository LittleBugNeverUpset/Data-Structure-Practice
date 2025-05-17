#pragma once
template <typename T>
struct LinkNode {
	T data;
	LinkNode* next;
};

template <typename T>
class LinkList{
private:
	LinkNode<T> * HeadPtr;
public:
	LinkList();
	LinkList(T elements[],int len);
	bool push_front(T element);
	bool push_back(T element);
	int Length();
	void PrintLinkList();
	bool InsertElement(T element,int Index); // �ڵ�Index��λ�ò���elementԪ��
	bool deleteElement(T element);
	bool deleteElementByIndex(int Index);

	

};




