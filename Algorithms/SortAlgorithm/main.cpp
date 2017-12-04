#include "select_sort.h"
#include "sort_compare.h"

using namespace std;
//主函数封装每个不同的测试函数，需要测试的时候就调用该函数
void Test_Time_Of_Sort(){
    cout << "Please input the length of array, the times of sort, and the time of sort:\n1 select sort\n2 insert sort" << endl;
    int length, name_of_sort, times;
    if(!(cin >> length >> name_of_sort >> times)){
        cout << "error input!" << endl;
        return ;
    }
    cout << "time:" << SortCompare::Time_Of_Sort(length,times,name_of_sort) << endl;

}

//测试排序
void Test_Sort(){
    cout << "Please input the length of array and the type of sort:(1 for shell sort, \n2 for insert sort, 3 for select sort, 4 for merge sort)" << endl;
    int length, type_of_sort;
    cin >> length >> type_of_sort;
    SortCompare::TestSort(length, type_of_sort);
}
int main() {
    Test_Sort();
    return 0;
}