# SimpleCompiler

## 简介

SimpleCompiler是一款基于ZLJ@NWPU提供的框架的编译器。该编译器基于SysY语言文法，使用Flex完成词法分析，使用Bison完成语法分析并生成AST，中端生成Dragon IR，一种自定义的IR。后端生成ARM32汇编语言。

### 指标

在提供的评测平台上，普通测例分别通过106/110（中端）、96/110（后端）。

试点测例通过62/138（中端）、54/138（后端）。中端可能在数组传参上存在一些问题。后端在处理bool值上存在部分问题。

### 优化

进行了机器无关优化：局部的常数传播（basic block内部）、常数合并、强度消减、代数化简。

## 源代码构成

```
.
├── CFG                # 程序生成的CFG会存放在这个文件夹
├── CMake
│   └── FindGraphviz.cmake
├── CMakeLists.txt
├── backend            # 后端，基于IR生成arm32汇编
├── cmake-build-debug  # 程序构建产物
├── common             # 一些通用的程序与数据结构
│   ├── Common.cpp
│   ├── Common.h
│   ├── Function.cpp
│   ├── Function.h
│   ├── SymbolTable.cpp
│   ├── SymbolTable.h
│   ├── Value.cpp
│   ├── Value.h
│   ├── ValueType.cpp
│   ├── ValueType.h
│   └── drawCFG
│       ├── drawCFG.cpp
│       └── drawCFG.h
├── frontend        # 前端，生成AST与IR
│   ├── AST
│   │      
│   └── DragonIR
│       ├── IRCode.cpp
│       ├── IRCode.h
│       ├── IRGenerator.cpp
│       ├── IRGenerator.h
│       ├── IRInst.cpp
│       └── IRInst.h
├── main.cpp
├── makeTestZip.sh # 产生测试包的脚本
├── optimizer      # 常数传播
│   ├── ConstPropagation.cpp
│   └── ConstPropagation.h
├── tests          # 测试程序
│   ├── std.c
│   ├── std.h
│   └── test.c
├── ubuntu.sh      # 配置环境的脚本
└── utils
    ├── getopt-port.cpp
    └── getopt-port.h
```

## 程序构建

请使用VSCode + WSL/Container/SSH + Ubuntu 22.04进行编译与程序构建。

首先需要安装程序的运行环境。首先需要保证存在一个名为**code**的用户，并在sudo环境下执行：

```shell
sh ubuntu.sh
```

安装完成之后，可以进行程序的构建：

```shell
# cmake根据CMakeLists.txt进行配置与检查，这里使用clang编译器并且是Debug模式
cmake -B cmake-build-debug -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++
# cmake，其中--parallel说明是并行编译
cmake --build cmake-build-debug --parallel
```

也可以使用vscode的“生成”完成构建

## 程序运行

命令格式：

```shell
minic -S [-a | -I | -C | -P] [-o output] source
minic -R source
```

选项-S -a 借助 flex+bison 产生抽象语法树 AST

选项-S -I 借助 flex+bison 产生线性 IR

选项-S -C 打印出生成的CFG

选项-S -P 打印出机器无关优化之后的IR

选项-o output 可把输出的抽象语法树或线性 IR 保存到文件中

选项-R 可直接运行得出结果

## 运行生成的ARM32汇编

使用以下的命令生成的arm32代码：

```shell
# 通过本程序翻译 test.c 成 ARM32 汇编
./cmake-build-debug/minic -S -o arm.S tests/test.c
# 把 test.c 通过 arm 版的交叉编译器 gcc 翻译成汇编
arm-linux-gnueabihf-gcc -S -include tests/std.h -o arm.S tests/test.c
```

使用以下命令使得arm32生成可执行程序：

```shell
# 通过 ARM gcc 编译器把汇编程序翻译成可执行程序，目标平台 ARM32
arm-linux-gnueabihf-gcc -static -g -o test tests/std.c arm.S
```

使用以下命令运行可执行程序：

```shell
qemu-arm-static test
```

在运行完之后，如果需要查看测试程序return结果，可以使用：

```shell
echo $?
```

## 编译器正确性评测

执行以下命令得到源代码压缩包：

```shell
sh makeTestZip.sh 
```

将压缩包上传至评测平台完成评测。

## 致后来者

这里列出了一系列 low fruit，后来者可以在本程序基础上进行优化

- [ ] 继续完成前端，针对试点测例作进一步的修正
- [ ] 重写后端对于bool处理方式的逻辑
- [ ] 基于半格运算实现常数传播
- [ ] 尝试基于线性扫描/图着色完成寄存器分配

