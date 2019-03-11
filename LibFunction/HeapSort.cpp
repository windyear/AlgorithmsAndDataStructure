//
// Created by windyear_office on 19-3-11.
//
// 堆排序主要有堆调整和堆排序两个子程序构成。
// 堆调整需要将root节点挪到合适的位置
void HeapAdjust(int* arr, int head, int length){
  int key = arr[head];
  int index = 2*head+1;
  while(index < length){
	if((index+1)<length && arr[index+1] > arr[index]){
	  ++index;
	}
	if(arr[index] > key){
	  arr[head] = arr[index];
	  head = index;
	  index = 2*index+1;
	}
	else{
	  break;
	}
  }
  // 找到位置放入key
  arr[head] = key;
}

void swap(int& a, int& b){
  int tmp = a;
  a = b;
  b = tmp;
}
void HeapSort(int* arr, int length){
  // 直接进行堆调整建堆
  // 从一半的位置开始，除去最后一行。
  for(int i = length/2-1; i >= 0; --i){
	HeapAdjust(arr, i, length);
  }
  // 然后每次交换头节点到后面一个节点，再对头结点进行对调整
  for(int i = length -1; i >= 0; --i){
	swap(arr[0], arr[i]);
	HeapAdjust(arr, 0, i); // 注意这里的位置是i;
  }
}

void TestHeapSort(){
  int arr1[] = {2, 4, 5, 1, -1, 7};
  HeapSort(arr1, 6);
  int arr2[] = {2, 3,3,1,1,7};
  HeapSort(arr2, 6);
  void(1);
}
