//
// Created by windyear_office on 19-2-26.
// 一个配合共享内存实现进程间同步的Posix信号量demo
#define SHM_KEY 1111
#define SEM_NAME "/TestSem"

#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
  // 打开一段共享内存。
  int shm_id = shmget(SHM_KEY, sizeof(int), 0666 | IPC_CREAT);
  // 判断是否打开成功
  if( shm_id < 0){
	printf("fail to create share memory.\n");
	return -1;
  }
  // 连接共享内存到进程空间，注意第二个参数一般为NULL
  void* shmptr = shmat(shm_id, NULL, 0);
  // 判断是否创建成功
  if(shmptr == (void*)-1){
	printf("fail to link the share memory.\n");
	return -1;
  }
  // 打开一个命名信号量
  // 因为做的是同步，所以初始信号量的值为０，写入数据后POST一下
  sem_t* sem_id = sem_open(SEM_NAME, O_CREAT, S_IRWXU, 0);
  int* data = static_cast<int*>(shmptr);
  while(1){
	// 从标准输入读入数据
	scanf("%d", data);

	// 通知读端取走，这里其实有一个同步的问题，如果输入很快的话，还来不及读取，但是因为会等待在标准输入，所以没问题
	sem_post(sem_id);
	// 输入-1退出进程
	if(*data == -1){
	  break;
	}
  }
  return 0;
}

