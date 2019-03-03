#include <iostream>
#include <assert.h>
#include <string.h>
#include "MyString.h"
#include <vector>
// 一些面试经常要手写的基础库函数的写法
class TestVirtualCTR{
public:
	//报错
	//virtual TestVirtualCTR();
	virtual void testVirtual()=0;
	virtual ~TestVirtualCTR(){}
};
// 子类的析构函数会调用父类的，所以报错未定义的引用。
class Derived: public TestVirtualCTR{
public:
	int data;
	void testVirtual(){
	  printf("Derived virtual function.");
	}
};
/*
 * memcpy:拷贝内存，需要支持任意类型
 * 注意处理内存重叠，边界条件
 * 不能保证des有足够的长度。
 * src要使用const
 * 返回目标内存开始的位置
 */
void* mymemcpy(void* des,const void* src,  int count){
	if(src == NULL || des == NULL || count <= 0){
	  return NULL;
	}
    // 复制指针
    void* des_tmp = des;
    // 转化为char*进行操作
    char* sr = (char*)src;
    char* de = (char*)des;
    // 进一步优化，如果两个指针相等
    if(des == src){
	  return des;
	}
    if(de > sr && de < sr+count){
	  // 从后面开始拷贝。
	  while(count > 0){
		*(de+count-1) = *(sr+count-1);
		--count;
	  }
	}
    else{
	  int i = 0;
	  while(i < count){
		*(de+i) = *(sr+i);
		++i;
	  }
	}
  (void*)des_tmp;
    return des_tmp;
}

// 字符复制strcpy
// 注意考虑重叠情况
// 返回char*
char* mystrcpy(char* dest, const char* src){
  assert(dest != NULL);
  assert(src != NULL);
  // 通过strlen求出长度
  if(dest == src){
	return dest;
  }
  size_t len = strlen(src);
  // 根据内存是否重叠进行复制。
  if(dest > src && dest <(src+len)){
	// 从后面开始复制
	size_t count = len - 1;
	while(count >= 0){
	  *(dest+count) = *(src+count);
	  --count;
	}
  }
  else{
	size_t count = 0;
	while(count < len){
	  *(dest+count) = *(src+count);
	  ++count;
	}
  }
  *(dest+len) = '\0';
  return dest;
}

void TestMyString(){
  MyString s0;
  MyString s1("hello");
  MyString s2(s0);
  printf("s0's size is:%d\n", s0.size());
  printf("s1's size is:%d\n", s1.size());
  std::vector<MyString> s_vec;
  s_vec.push_back(s0);
  s_vec.push_back(s1);
  s_vec.push_back("nice!");
  MyString test(s1);
}
int main() {
  //std::cout << "Hello, World!" << std::endl;
  //char testa[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  //memcpy(testa, testa+3, 3);
  //memcpy(testa, testa+2, 3);
  //char testb[] = {'h', 'h'};
  //char* c = mystrcpy(testa, testb);
  //printf("%s\n", c);
  //Derived derived;
  TestMyString();
  return 0;
}