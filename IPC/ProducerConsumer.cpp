//
// Created by windyear_office on 19-2-28.
// 简单的用信号量做同步的生产者消费者
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t empty, full;

int produce = 0, consum = 0;

void* producer(void* data){
  while(1){
	sem_wait(&empty);
	printf("producer produce %d.\n", produce++);
	sem_post(&full);
	sleep(1);
  }
}

void* cosumer(void* data){
  while(1){
	sem_wait(&full);
	printf("consumer consum %d.\n", consum++);
	sem_post(&empty);
	sleep(1);
  }
}

int main(){
  sem_init(&empty, 0, 1);
  sem_init(&full, 0, 0);
  pthread_t p1, p2;
  if(pthread_create(&p1, NULL, producer, NULL)){
	printf("thread create fail.\n");
  }
  if(pthread_create(&p2, NULL, cosumer, NULL)){
	printf("thread create fail.\n");
  }
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
}