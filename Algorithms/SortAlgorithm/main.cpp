#include <iostream>
#include "select_sort.cpp"
using namespace std;
int main() {
    std::cout << "please enter the length of the array of int:" << std::endl;
    int N;
    cin >> N;
    cout << "enter the elements:";
    int* int_array = new int[N];
    for(int i = 0; i < N; i++){
        cin >> int_array[i];
    }
    SelectSort select_sort(N, int_array);
    select_sort.Select_Sort();
    select_sort.ShowArray();
    return 0;
}