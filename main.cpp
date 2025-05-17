#include <bits/stdc++.h>
#include"SqList.h"
#include"LinkList.h"
//#include<string>

using namespace std;

int main() {
	//À≥–Ú±Ì≤‚ ‘
	//SqList<int> list;
	////list.InitSqList();
	//for (int i = 0; i < 20; i++) {
	//	list.ListInsert(i * 2 + 1, i);
	//}
	//list.PrintSqList();
	//cout << "Find(9): \t" << list.Find(9);
	

	//¡–±Ì≤‚ ‘
	int arr[] = { 1,2,3,4 };
	LinkList<int> Ls(arr, 4);
	Ls.InsertElement(10, 2);
	cout << Ls.Length();
	Ls.PrintLinkList();
}

