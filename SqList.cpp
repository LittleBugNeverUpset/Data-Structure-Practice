#include "SqList.h"
#include<iostream>
#include<string>
#define InitSize 20
template<typename T>
SqList<T>::SqList() {
    /*data(nullptr), Length(0), MaxSize(0);*/
    this->MaxSize = 20;
    this->Length = 0;
    this->data = new T[InitSize];
	std::cout << "SqList Init \n";
}


template<typename T>
void SqList<T>::PrintSqList(){
    if (this == nullptr) return;
    for (int i = 0; i < this->Length; i++) {
        std::cout << this->data[i] << '\t';
    }
}

template<typename T>
bool SqList<T>::ListInsert(T element, int Index) {
    // 检查插入位置的索引是否合法
    if (Index > this->Length || Index < 0) {
        return false;
    }
    // 检查是否需要扩容
    if (this->Length + 1 > this->MaxSize) {
        // 扩容，将最大容量翻倍
        this->MaxSize *= 2;
        // 分配新的更大容量的数组
        T* NewData = new T[this->MaxSize];
        // 复制原数组中索引小于 Index 的元素到新数组
        for (int i = 0; i < Index; ++i) {
            NewData[i] = this->data[i];
        }
        // 在新数组的 Index 位置插入新元素
        NewData[Index] = element;

        // 复制原数组中索引从 Index 开始的元素到新数组的下一个位置
        for (int i = Index; i < this->Length; ++i) {
            NewData[i + 1] = this->data[i];
        }
        // 释放原数组的内存
        T* p = this->data;
        this->data = NewData;
        delete[] p;
    }
    else {
        // 不需要扩容时，将 Index 及之后的元素依次后移一位
        for (int i = this->Length; i > Index; --i) {
            this->data[i] = this->data[i - 1];
        }
        // 在 Index 位置插入新元素
        this->data[Index] = element;
    }
    // 插入成功后，列表长度加 1
    this->Length++;
    return true;
}
template<typename T>
bool SqList<T>::DeleteElement(int Index){
    if(Index < 0 || Index >= this->Length) return false;
    else {
        for (int i = Index; i < this->Length - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->Length--;
        return true;
    }
}
template<typename T>
int SqList<T>::Find(T element){
    if (this->data != nullptr) {
        for (int i = 0; i < this->Length;i++) {
            if (this->data[i] == element) return i;
        }
    }
    return -1;
}
// 显式实例化模板（添加在.cpp文件末尾）
template class SqList<int>;
template class SqList<double>; 
template class SqList<char>;
template class SqList<float>;
template class SqList<std::string>;
// 明确告诉编译器需要实例化哪些数据类型版本
// CPP还是太硬核了





