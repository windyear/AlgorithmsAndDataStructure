---
title: learningSocket
date: 2016-12-12 22:31:16
tags: 
- python
- socket
- 网络编程
- 服务器
---
# 简单的本地socket编程以及能够下载网页的socket客户端
## 程序说明
1. 使用python封装好的网络编程模块socket,可以快速实现socke编程开发。
2. 服务端的主要操作是首先有一个套接字实例，然后去监听某个地址和端口。客户端同样这样，使用connect()函数来连接服务器。此时，服务器的accept()方法一直阻塞到有连接并且返回一个套接字，地址的元组。通过套接字实例的send和recv方法可以实现发送和接受消息。
3. 使用完之后就可以关闭socket。
## 程序如下：
1. 服务器：
``` python
`import socket

s=socket.socket()

host=socket.gethostname()
port=1234

s.bind((host,port))

s.listen(5)

while(True):
    c,addr =s.accept()
    print('Got connection from',addr)
    c.send('Thank you for connecting'.encode())
    c.close()`
```
2. 客户端：
    #!/usr/bin/python
    # -*- coding:utf-8 -*-
    import socket
    
    s=socket.socket()
    
    host=socket.gethostname()
    port=1234
    
    s.connect((host,port))
    print(s.recv(1024).decode())
    
    #test=input("Just testing:")
    #raw_input()![图片不见了哟](http://i.imgur.com/W8jyeQL.png)
3. 运行结果
![图片不见了哟](http://i.imgur.com/W8jyeQL.png)
![](http://i.imgur.com/3rMIFqF.png)
## 各种坑
- 首先是bind和connect函数的参数是一个元组而不是两个参数。
- 第二个大坑是python3的str和byte类型明显的区分，所以通过send发送的字符串要先进行编码或者直接`b'Hello world'`这样表明是是byte类型的，同理接收时要解码。
- 无法搞清楚端口号明明已经设置好了，但是连接时会换端口，不知道是什么原因。

## 下面是一个下载网页的程序
### 核心原理就是建立好socket连接之后发送GET请求，服务器会根据请求的内容返回内容，然后处理内容将其保存到文件中就可以
### 代码：
#!/usr/bin/python
# -*- coding: utf-8 -*-
    import socket
    s=socket.socket()
    
    s.connect(('www.sina.com.cn',80))
    s.send(b'GET / HTTP/1.1\nHost: www.sina.com.cn\nConnection: keep-alive\n\n')
    
    buffer=[]
    while True:
    d=s.recv(1024)
    if d:
    buffer.append(d)
    else:
    break
    data=b''.join(buffer)
    s.close()
    
    #header,html = data.split(b'\n\n',1)
    #print(header.decode('utf-8'))
    
    with open(r'D:\windyear_files\testfiles\sina_test.html','wb') as f:
    f.write(data)
**运行的结果是下载到一个网页保存为html文件**

### 走过的坑
1. 首先是windows系统和linux对于回车的使用是不同的，只需要\n而非\r\n。由此引发了一个关于split函数解包的问题，第二个参数指定返回多少个值，但是不能忽略不能分割的情况。
2. 其次是GET请求的参数问题，一开始的Connection参数是close,这时下载了一个错误的网页，后来使用chrome的开发者工具了解发哦正确的参数应该是keep-alive。

##总结
由于python封装好了socket模块，所以使用起来比较简单。但是很多细节问题必须自己实现一次才能发现。今天虽然做的不多，但是也算是有一些收获，希望自己可以坚持下去。