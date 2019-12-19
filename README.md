## Gah0 Blockchain

#### Introduction

a simple blockchain demo in C,  just for learning !



#### Dependencies libs

https://github.com/jb55/sha256.c/blob/master/sha256.c



#### Build the blockchain

`git clone -b master --single-branch https://github.com/Gah0/blockchain.git`

`cd blockchain`

`make && ./client.out`



#### Welcome  to feedback!



## Blockchain 中文版介绍

#### 介绍

我用C语言写了一个区块链的样品，用于学习使用。



#### 依赖库

此处使用了开源的sha256加密依赖库。

https://github.com/jb55/sha256.c/blob/master/sha256.c



#### 运行blockchain

`git clone -b master --single-branch https://github.com/Gah0/blockchain.git`

`cd blockchain`

`make && ./client.out`



#### 欢迎大家积极反馈！

```
*我会尽量保持呼吸
```

-------------------
#### 后言

本来我使用的是 SHA1 进行加密
由于 SHA1 在 Little-ending 上有 bug，需要交换字节，而且嵌入式机器上的部分处理器也有 Little-ending 模式，因此我们尽量避免出现问题，所以被我弃用。

https://github.com/clibs/sha1


