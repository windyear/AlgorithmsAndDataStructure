//
// Created by windyear_office on 19-3-3.
// 懒汉和饿汉模式的singleton

#ifndef LIBFUNCTION_SINGLETON_H
#define LIBFUNCTION_SINGLETON_H
#include <cstdlib>
class Singleton{
private:
	Singleton(){}
	static Singleton* instance_;
public:
	static Singleton* GetInstance(){
	  if(instance_ == NULL){
		instance_ = new Singleton();
	  }
	  return instance_;
	}
};

class SingletonStatic{
private:

	SingletonStatic(){}
	static SingletonStatic* instance_;
public:
	static SingletonStatic* GetInstance(){
	  return instance_;
	}
};

SingletonStatic* SingletonStatic::instance_ = new SingletonStatic();
#endif //LIBFUNCTION_SINGLETON_H
