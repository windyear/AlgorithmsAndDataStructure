#include "select_sort.h"
#include "sort_compare.h"

using namespace std;
int main() {
    cout << "Please input the length of array, the times of sort, and the time of sort:\n1 select sort\n2 insert sort" << endl;
    int length, name_of_sort, times;
    if(!(cin >> length >> name_of_sort >> times)){
        cout << "error input!" << endl;
        return -1;
    }
    cout << "time:" << SortCompare::Time_Of_Sort(length,times,name_of_sort) << endl;
    return 0;
}