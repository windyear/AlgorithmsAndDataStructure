//
// Created by windyear_office on 19-3-3.
// 一个自行实现的简单的string类

#ifndef LIBFUNCTION_MYSTRING_H
#define LIBFUNCTION_MYSTRING_H
#include <cstring>

class MyString{
public:
	MyString():data_(new char[1]){
	  *data_ = '\0';
	}
	MyString(const MyString& s){
	  int len = strlen(s.data_);
	  data_ = new char[len+1];
	  strcpy(data_, s.data_);
	}
	MyString(const char* c){
	  if( c == NULL){
		data_ = new char[1];
		*data_ = '\0';
	  }
	  else{
		int len = strlen(c);
		data_ = new char[len+1];
		strcpy(data_, c);
	  }
	}
	MyString& operator=(const MyString& s){
	  // 处理自复制
	  if(this == &s){
		return *this;
	  }
	  char* temp = data_;
	  int len = strlen(s.data_);
	  data_ = new char[len+1];
	  strcpy(data_, s.data_);
	  delete [] temp;
	  return *this;
	}
	~MyString(){
	  if(data_ != NULL){
		delete [] data_;
	  }
	}

	const char* c_str() const{
	  return data_;
	}

	size_t size() const{
	  return strlen(data_);
	}
private:
	char* data_;
};
#endif //LIBFUNCTION_MYSTRING_H
