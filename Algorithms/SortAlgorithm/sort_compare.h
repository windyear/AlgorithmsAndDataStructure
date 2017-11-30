//
// Created by windyear_office on 17-11-30.
//

#ifndef SORTALGORITHM_SORT_COMPARE_H
#define SORTALGORITHM_SORT_COMPARE_H

#include <sys/timeb.h>
#include <iostream>
#include "select_sort.h"
#include "create_test_array.h"
#include "insert_sort.h"

using namespace std;
class SortCompare{
public:
    static double Time_Of_Sort(int N, int times, int name_of_sort){
        struct timeb start_time, end_time;
        ftime(&start_time);
        for(int i = 0; i < times; i++){
            Test_Sort(N, name_of_sort);
        }
        ftime(&end_time);
        return (end_time.time * 1000 + end_time.millitm - start_time.millitm - start_time.time * 1000);
    }

    static void Test_Sort(int N, int name_of_sort) {
        if (N == 1000) {
            CreateTestArray<int, 1000> test_select_array, test_insert_sort, test_insert_sort2;
            int *p_test_select_array = test_select_array.GetArrayAdress();
            int *p_test_insert_sort = test_insert_sort.GetArrayAdress();
            //测试选择排序
            switch(name_of_sort) {
                case 1:
                {
                    SelectSort *select_sort = new SelectSort(N, p_test_select_array);
                    select_sort->Select_Sort();
                    //测试发现插入排序写错了
                    delete select_sort;
                    break;
                }
                case 2:
                {
                    InsertSort *insert_sort = new InsertSort(N, p_test_insert_sort);
                    insert_sort->Insert_Sort2();
                    delete insert_sort;
                    break;
                }
                default:
                    break;
            }
        }else if(N == 100){
            CreateTestArray<int, 100> test_select_array, test_insert_sort, test_insert_sort2;
            int *p_test_select_array = test_select_array.GetArrayAdress();
            int *p_test_insert_sort = test_insert_sort.GetArrayAdress();
            //测试选择排序
            switch(name_of_sort) {
                case 1:
                {
                    SelectSort* select_sort = new SelectSort(N, p_test_select_array);
                    select_sort->Select_Sort();
                    //测试发现插入排序写错了
                    select_sort->ShowArray();
                    delete select_sort;
                    break;
                }
                case 2:
                {
                    InsertSort *insert_sort = new InsertSort(N, p_test_insert_sort);
                    insert_sort->Insert_Sort();
                    delete insert_sort;
                    break;
                }
                default:
                    break;
            }
        }else{
            cout << "Please input the number 1000 or 100!" << endl;
        }
    }
};
#endif //SORTALGORITHM_SORT_COMPARE_H
