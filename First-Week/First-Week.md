##  搭建Windows 10下的QT开发环境
    缘由：逆向的应用的开发方向是 "windows下基于C++/Qt的应用程序"
版本：Qt 5.12.10 /Qt Creator 4.9 

## 《逆向工程核心原理》和IDA Pro 7.0
这本书大致浏览一遍，觉得有例子和知识点互补一起学习效率比较高，其中有很逆向例子供自学模仿，所以选择了这本书。再者，是逆向软件的选择，书上提供了两个一个是OllyBug和IDA，后者更为专业一点，随后询问有相关经验的同学所以也是选择了后者，同时他也推荐我《IDA权威指南》进行阅读，所以目前暂定任务是通过这两本书进行系统的学习和尝试。

## 这周目标：
1.尝试跟随书籍第1、2、3章内容简单将简单的窗口打印Hello World！的程序逆向更改为打印Hello Joker！书上的例子只是简单的windows的api ，qt也只是上层封装，所以大致思路应该是一致的。

2.熟悉常见的intel的指令集。如：IA-32（书中的第四章进行了相关的讲解）

**解决几个疑问：**

1.如何解决确定调试起点的问题

2.分析指令的娴熟程度不够



## 基础知识（基本的反汇编算法，通过分析二进制数据获取汇编代码）：

1. **线性扫描反汇编**

   实现方式：（简单易理解，直接翻译二进制代码）

   优势：能覆盖所有的代码

   劣势：代码中可能混有数据；不能通过识别分支等非线性指令来了解程序的控制流

   采用例子：GDB，WinDgb，objdump 

2. **递归下降反汇编**

   实现方式：根据指令的不同类型【**靠执行权交付区分**】（顺序流，条件分支，无条件分支）

   优势：强调控制流，

   



## 目标一的实现
步骤1：先正向开发一个使用消息框打印HelloWorld的程序
具体代码如下（具体项目代码见./TestApplication）：

```c++
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    msgLable=new QLabel(this);

    showMessage("Hello World!");
}

Dialog::~Dialog()
{

}

void Dialog::showMessage(QString msg)
{
    if(msgLable!=nullptr)
    {
        msgLable->setText(msg);
        msgLable->show();
    }
}
```

步骤2：根据书中的内容和IDA权威指南的操作经进行逆向。