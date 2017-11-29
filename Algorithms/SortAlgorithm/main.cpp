#include <iostream>
#include "select_sort.h"
#include "insert_sort.h"
#include "create_test_array.h"
using namespace std;
int main() {
//    std::cout << "please enter the length of the array of int:" << std::endl;
     int N = 1000;
//    cin >> N;
    CreateTestArray<int, 1000> test_array, test_insert_sort;
    int* p_test_array = test_array.GetArrayAdress();
//    cout << "enter the elements:";
//    int* int_array = new int[N];
//    for(int i = 0; i < N; i++){
//        cin >> int_array[i];
//    }
    //测试选择排序
    SelectSort* select_sort= new SelectSort(N, p_test_array);
    select_sort->Select_Sort();
    cout << "Is the array sorted?" << endl;
    cout << select_sort->IsShorted() << endl;
    select_sort->ShowArray();
    //测试发现插入排序写错了
//    delete[] int_array;
    delete select_sort;
//    测试插入排序
      InsertSort* insert_sort= new InsertSort(N, test_insert_sort.GetArrayAdress());
      insert_sort->Insert_Sort();
      cout << "Is the array sorted?" << endl;
      cout << insert_sort->IsShorted() << endl;
      insert_sort->ShowArray();
//    delete[] int_array;
    delete insert_sort;
    return 0;
}