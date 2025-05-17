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
    // ������λ�õ������Ƿ�Ϸ�
    if (Index > this->Length || Index < 0) {
        return false;
    }
    // ����Ƿ���Ҫ����
    if (this->Length + 1 > this->MaxSize) {
        // ���ݣ��������������
        this->MaxSize *= 2;
        // �����µĸ�������������
        T* NewData = new T[this->MaxSize];
        // ����ԭ����������С�� Index ��Ԫ�ص�������
        for (int i = 0; i < Index; ++i) {
            NewData[i] = this->data[i];
        }
        // ��������� Index λ�ò�����Ԫ��
        NewData[Index] = element;

        // ����ԭ������������ Index ��ʼ��Ԫ�ص����������һ��λ��
        for (int i = Index; i < this->Length; ++i) {
            NewData[i + 1] = this->data[i];
        }
        // �ͷ�ԭ������ڴ�
        T* p = this->data;
        this->data = NewData;
        delete[] p;
    }
    else {
        // ����Ҫ����ʱ���� Index ��֮���Ԫ�����κ���һλ
        for (int i = this->Length; i > Index; --i) {
            this->data[i] = this->data[i - 1];
        }
        // �� Index λ�ò�����Ԫ��
        this->data[Index] = element;
    }
    // ����ɹ����б��ȼ� 1
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
// ��ʽʵ����ģ�壨�����.cpp�ļ�ĩβ��
template class SqList<int>;
template class SqList<double>; 
template class SqList<char>;
template class SqList<float>;
template class SqList<std::string>;
// ��ȷ���߱�������Ҫʵ������Щ�������Ͱ汾
// CPP����̫Ӳ����





