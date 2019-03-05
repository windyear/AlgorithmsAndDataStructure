### POSIX信号量加共享内存实现两个进程简单通信(一收一发)

#### 要点

- 用了POSIX具名信号量，可以在进程间共享
- 用共享内存当做通信介质
- 信号量初始值为０，实现同步的功能，需要发送端写入信息后通知接收方接收。
- 其他细节在代码注释中
- POSIXSem_w.cpp为发送端代码，POSIXSem_r.cpp为接收端代码。

### 代码

- POSIXSem_w.cpp

  ```c++
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
  ```

- 接收端代码

  ```c++
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
  	// 等待信号量通知
  	sem_wait(sem_id);
  	// 从标准输入读入数据
  	printf("%d\n", *data);
  	// 通知读端取走，这里其实有一个同步的问题，如果输入很快的话，还来不及读取，但是因为会等待在标准输入，所以没问题
  	// 输入-1退出进程
  	if(*data == -1){
  	  break;
  	}
    }
    return 0;
  }
  ```

  