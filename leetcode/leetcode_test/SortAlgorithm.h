//
// Created by windyear_office on 19-2-22.
//

#ifndef LEETCODE_TEST_SORTALGORITHM_H
#define LEETCODE_TEST_SORTALGORITHM_H
#include <algorithm>
class SortAlgorithm{
public:
	void QuickSort(int* arr, int start, int end){
	  if(start < end){
		int index = Partition(arr, start, end);
		QuickSort(arr, start, index-1);
		QuickSort(arr, index+1, end);
	  }
	}

	// 还好有写一写，写错了。
	int Partition(int* arr, int low, int high){
	  // 左右指针法，需要一个变量来保存最后一个元素
	  int key = arr[high];
	  int right = high;
	  while(low < high){
		// 如果不写等于，会出不了循环
		while(low < high && arr[low] <= key){
		  ++low;
		}
		while(low < high && arr[high] >= key){
		  --high;
		}
		// 交换
		int tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
	  }
	  std::swap(arr[low], arr[right]);
	  return low;
	}

	void TestQuickSort(){
	  int arr1[] = {3, 3, 3,3};
	  QuickSort(arr1, 0, 3);
	  int arr2[] = {7, 4,2};
	  QuickSort(arr2, 0, 2);
	  int arr3[] = {1, 2, 3};
	  QuickSort(arr3, 0, 2);
	  int arr4[] = {2,1};
	  QuickSort(arr4, 0, 1);
	  printf("haha");
	}
};
#endif //LEETCODE_TEST_SORTALGORITHM_H
