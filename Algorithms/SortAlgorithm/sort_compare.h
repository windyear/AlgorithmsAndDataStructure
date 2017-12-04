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
#include "shell_sort.h"
#include "merge_sort.h"

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
            //块结束之后自动调用析构函数
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
    //1:shell sort; 2:insert sort; 3:select sort;
    static void TestSort(int N, int type_of_sort){
        switch(type_of_sort){
            case 1:
            {
                CreateTestArray<int, 10000> test_array;
                int* p_array = test_array.GetArrayAdress();
                ShellSort shell_sort(N, p_array);
                shell_sort.ShowArray();
                shell_sort.Shell_Sort();
                shell_sort.ShowArray();
                break;
            }
            case 2:
            {
                CreateTestArray<int, 10000> test_array;
                int* p_array = test_array.GetArrayAdress();
                SelectSort select_sort(N, p_array);
                select_sort.ShowArray();
                select_sort.Select_Sort();
                select_sort.ShowArray();
                break;
            }
            case 3:
            {
                CreateTestArray<int, 10000> test_array;
                int* p_array = test_array.GetArrayAdress();
                InsertSort insert_sort(N, p_array);
                insert_sort.ShowArray();
                insert_sort.Insert_Sort();
                insert_sort.ShowArray();
                break;
            }
            case 4:
            {
                CreateTestArray<int, 1000> test_array;
                int* p_array = test_array.GetArrayAdress();
                MergeSort merge_sort(N, p_array);
                merge_sort.ShowArray();
                //这里注意传参数不要传错，数组是从下标为０开始的。
                merge_sort.Merge_Sort(0, N-1);
                merge_sort.ShowArray();
            }
            default:
                break;
        }
    }
};
#endif //SORTALGORITHM_SORT_COMPARE_H
