# C++并发编程实战
参考GPT给出的教程学习C++并发编程
## 资料
- [原书](https://github.com/ZhouZhaoJi/Library/blob/master/Programming/C++%E5%B9%B6%E5%8F%91%E7%BC%96%E7%A8%8B%E5%AE%9E%E6%88%98.pdf)
- [Cpp-Concurrency-in-Action-2ed](https://github.com/downdemo/Cpp-Concurrency-in-Action-2ed/tree/master)

## GPT学习大纲
**🗓️ 多线程学习计划表（6 周冲刺版）**

### ✅ Week 1：线程基础与 mutex 同步
---
**🎯 目标**
- 理解 std::thread 使用方式
- 掌握 mutex 与 lock_guard 基本线程同步

**📚 学习内容**
- std::thread 的创建、join/detach、传参方式
- std::mutex, std::lock_guard, std::unique_lock
- 数据竞争与 race condition 的概念

**🧪 编码练习**
- 写一个多线程打印数字的程序（2 个线程交替打印奇偶数）
- 实现一个线程安全的计数器（加锁封装）
- 编写两个线程共享资源同时访问，演示数据竞争 vs 加锁后的安全


### ✅ Week 2：条件变量 & 异步执行
---
**🎯 目标**
- 掌握 condition_variable 用法
- 学会使用 std::async、future 处理异步任务

**📚 学习内容**
- std::condition_variable、wait / notify_one / notify_all
- 实现生产者-消费者模式
- std::future 和 std::async

**🧪 编码练习**
- 实现一个阻塞队列（BlockingQueue）
- 写一个异步任务提交器，使用 std::async 获取返回值
- 实现一个线程任务执行完再通知主线程的逻辑（用 condition_variable）


**✅ Week 3：原子操作与线程池雏形**
---
**🎯 目标**
- 理解 std::atomic、CAS 思维
- 搭建简单线程池结构

**📚 学习内容**
- std::atomic 类型、compare_exchange_* 操作
- CAS 与 ABA 问题
- 线程池设计思路：任务队列 + 工作线程

**🧪 编码练习**
- 实现一个原子变量加法操作和自旋锁
- 写一个简单线程池类：提交任务 + 多线程执行 + join 等待
- 在线程池中用 future 获取任务执行结果


**✅ Week 4：线程安全数据结构**

**🎯 目标**
- 编写线程安全的 Stack / Queue
- 使用 RAII 和 lock 编程技巧

**📚 学习内容**
- shared_ptr 封装线程返回值
- 读写锁（shared_mutex）
- 编写线程安全容器封装技巧

**🧪 编码练习**
- 实现一个线程安全栈 SafeStack<T>（模板类）
- 使用 std::shared_mutex 写一个多读单写的 map
- 模拟银行转账程序，防止死锁（使用 std::lock）


**✅ Week 5：并发模式与线程调度**
---
**🎯 目标**
- 掌握常用并发设计模式
- 学习实现定时任务/延迟任务线程

**📚 学习内容**
- 生产者-消费者、任务队列、Reactor 模式简析
- 定时任务调度器实现方法
- 自定义 TimerThread 类

**🧪 编码练习**
- 实现一个定时任务执行器（支持定时调度函数）
- 实现延迟执行（类似 JavaScript 的 setTimeout）
- 用线程池并行处理 100 个计算密集型任务，统计总耗时


**✅ Week 6：项目整合 + 性能调优**

**🎯 目标**
- 综合构建多线程模块
- 学会排查和调试多线程程序

**📚 学习内容**
- 死锁调试技巧：gdb, valgrind, perf
- false sharing、cache line、NUMA 等性能优化思路
- 阅读 folly::ThreadPoolExecutor 或 TBB 源码结构

**🧪 编码练习**
- 开发一个线程池 + 定时器的综合工具类
- 写一个并发爬虫模拟器（从多个 URL 同时请求，保存内容）
- 调试一个故意死锁的例子，并记录发现与解决过程