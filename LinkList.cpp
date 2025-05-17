#include "LinkList.h"
#include<iostream>
// 模板类构造函数的实现
template<typename T>
LinkList<T>::LinkList() {
    this->HeadPtr = new LinkNode<T>;
    this->HeadPtr->next = nullptr;
}
  
template<typename T>
LinkList<T>::LinkList(T elements[],int len) { // 尾插法同传入数组保持一致
    this->HeadPtr = new LinkNode<T>;
    this->HeadPtr->next = nullptr;
    LinkNode<T>* p = this->HeadPtr;
    for (int i = 0; i < len; i++) {
        LinkNode<T>* temp = new LinkNode<T>;
        temp->data = elements[i];
        temp->next = nullptr;
        p->next = temp;
        p = p->next;
    }

}
template<typename T>
void LinkList<T>::PrintLinkList() {
    LinkNode<T>* p;
    p = this->HeadPtr->next;
    if (p != nullptr) {
        while (p != nullptr) {
            std::cout << p->data << '\t';
            p = p->next;
        }
    }
}

template<typename T>
bool LinkList<T>::InsertElement(T element, int Index){
    int len = this->Length();
    if (Index < 0 || Index > len) return false;
    else {
        LinkNode<T>* pre = this->HeadPtr;
        LinkNode<T>* p = this->HeadPtr->next;
        int i = 0;
        while (i < Index) {
            i++;
            p = p->next;
            pre = pre->next;
        }
        LinkNode<T>* newNode = new LinkNode<T>;
        newNode->data = element;
        pre->next = newNode;
        newNode->next = p;
        return false;
    }
}

template<typename T>
bool LinkList<T>::deleteElement(T element)
{
    return false;
}
template<typename T>
bool LinkList<T>::deleteElementByIndex(int Index)
{
    return false;
}
template<typename T>
bool LinkList<T>::push_front(T element)
{
    return false;
}

template<typename T>
bool LinkList<T>::push_back(T element)
{
    return false;
}

template<typename T>
int LinkList<T>::Length(){
    if (this->HeadPtr == nullptr) return -1;
    int ans = 0;
    LinkNode<T>* p = this->HeadPtr;
    while (p->next != nullptr) {
        ans++;
        p = p->next;
    }
    return ans;
}
template class LinkList<int>;
template class LinkList<char>;
