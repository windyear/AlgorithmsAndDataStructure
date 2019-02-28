//
// Created by windyear_office on 19-2-28.
// 一个用文件锁实现进程只能打开单个实例的程序。
#include <fcntl.h>    // fcntl sturct flock
#include <stdlib.h>  // exit
#include <stdio.h>  // printf
#include <unistd.h> // close
#include <errno.h> // errno
#include <string.h> // strlen
#define lockfile "OneInstance.pid"
int LockFile(int fd){
  // flock结构体表明锁的一些设置
  struct flock f1;
  f1.l_type = F_WRLCK; // 设置为唯一写锁，如果是同一个进程不会失败，会替换原来的锁。
  f1.l_start = 0;
  f1.l_whence = SEEK_SET;
  f1.l_len = 0; // 设置锁的大小为为整个文件
  return fcntl(fd, F_SETLK, &f1); //出错会返回,errno为EACCES或者EAGAIN。
}

int main(){
    int fd;
    fd = open(lockfile, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd < 0){
	  printf("can't open the lock file.\n");
	  exit(1);
	}
    // 进行加锁操作
    if(LockFile(fd) < 0){
	  if(errno == EACCES || errno == EAGAIN){
		printf("The process only can have one instance.\n");
		close(fd);
		return 1;
	  }
	  printf("can't lock.\n");
	  exit(-1);
	}

    // 截断文件
  ftruncate(fd, 0);
  char buf[32];
  sprintf(buf, "%ld", (long)getpid());
  write(fd, buf, strlen(buf)+1);
  while(1){
	printf("It's the one instance process.\n");
	sleep(1);
  }
  return 0;
}
