
# c++ 学习手册

## vscode 环境配置

1. 配置``launch.json``

    ```json
    {
        // 使用 IntelliSense 了解相关属性。 
        // 悬停以查看现有属性的描述。
        // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Debug C++",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}/${fileBasename}.a",
                //gdb地址， 如果仅安装了gcc，还需要单独安装一个gdb
                "miDebuggerPath": "/usr/bin/gdb", 
                "args": [],
                "stopAtEntry": false,
                "externalConsole": false,
                "MIMode": "gdb",
                "cwd": "${workspaceFolder}",
                //关联tasks.json， 用于指定执行哪个任务
                "preLaunchTask": "g++",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ]
            }
        ]
    }
    ```

2. 配置``tasks.json``文件

    ```json
    {
        "version": "2.0.0",
        "command": "g++",
        "args": ["-g", "-std=c++14", "${file}", "-o", "${workspaceRoot}/${fileBasename}.a"],
        // "problemMatcher":{
        //     "owner": "cpp",
        //     "fileLocation":["relative", "${workspaceRoot}"],
        //     "pattern":{
        //         "regexp": "^([^\\\\s].*)\\\\((\\\\d+,\\\\d+)\\\\):\\\\s*(.*)$",
        //         "file": 1,
        //         "location": 2,
        //         "message": 3
        //     }
        // }
    }
    ```

3. 可以使用debug按钮执行当前的c++脚本了;

## linux 环境下执行c++代码

简单的代码

```shell
# g++
g++ -o test demo.cpp 

# clang++
clang++ -o test demo.cpp

```

## c++ 头文件 & 文件引用

### 头文件作用

1. 声明函数、类和变量：头文件通常包含了函数、类和变量的声明，而不是它们的定义。这允许在不暴露实现细节的情况下，让其他源文件知道这些实体的存在和如何使用它们。

2. 模块接口：头文件可以被视为模块的接口，提供了其他代码可以使用的接口。这种分离接口和实现的方式有助于提高代码的可维护性和可重用性。

3. 避免重复定义：当多个源文件需要共享相同的函数、类或变量时，头文件中的声明允许它们在不产生重复定义错误的情况下共享这些实体。

4. 预处理指令：头文件可以包含预处理指令，如#ifndef、#define和#endif，用于防止头文件的重复包含，提高编译效率。

5. 编译器检查：编译器可以在编译时检查头文件中声明的函数、类和变量的使用情况，帮助发现潜在的错误。

典型的C++程序结构包括.cpp文件（源文件）和.h文件（头文件）。.cpp文件包含函数和类的定义以及程序的实现细节，而.h文件包含相应的声明，供其他源文件使用。这种分离使得代码更加清晰、模块化，并且易于维护和扩展。

### 使用方式

1. 定义一个c++代码文件的头文件，一般定义和文件相同的.h文件
    '''cpp
    void test_template();
    '""

2. 在实现的cpp文件中导入头文件

    ```cpp
    #include "l_template.h"
    #include <iostream>
    #include <string>

    template <typename T>
    inline T const &Max(T const &a, T const &b)
    {
        return a < b ? b : a;
    }

    void test_template()
    {
        int i = 39;
        int j = 20;
        std::cout << "Max(i, j): " << Max(i, j) << std::endl;

        double f1 = 13.5;
        double f2 = 20.7;
        std::cout << "Max(f1, f2): " << Max(f1, f2) << std::endl;

        std::string s1 = "Hello";
        std::string s2 = "World";
        std::cout << "Max(s1, s2): " << Max(s1, s2) << std::endl;
    }
    ```

3. 在调用出引入头文件``#include "learn/l_template.h"``;

4. 编译注意事项：
    + c++在调用头文件的时候，需要将对应的cpp文件加入编译命令中，否则解释器会报错找不到引用的函数；
    + c++直接引入cpp文件，可以避免在编译的时候需要加入.h文件对应的cpp文件;

    ```shell
     g++ learn.cpp learn/l_template.cpp
    ```

## vscode多任务，定制指令

1. 在``tasks.json``中增加需要执行的任务指令。

    ```Json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "type": "cppbuild",
                "label": "build C++/python",
                "command": "/usr/bin/g++",
                "args": [
                    "-fdiagnostics-color=always",
                    "-g",
                    "${file}",
                    "-I",
                    "/home/ez/miniconda3/include/python3.11",
                    "-o",
                    "${fileDirname}/target/${fileBasenameNoExtension}.out"
                ],
                "options": {
                    "cwd": "${fileDirname}"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "detail": "调试器生成的任务。"
            },
            {
                "label": "Build C++",
                "type": "cppbuild",
                "command": "g++",
                "args": [
                    "-fdiagnostics-color=always",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}/target/${fileBasenameNoExtension}.out"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "presentation": {
                    "echo": true,
                    "reveal": "always",
                    "focus": true,
                    "panel": "dedicated"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "detail": "Compile and run C++ program"
            },
            {
                "label": "run",
                "dependsOn": [
                    "Build C++"
                ],
                "type": "process",
                "presentation": {
                    "echo": true,
                    "reveal": "always",
                    "focus": true,
                    "panel": "shared",
                    "showReuseMessage": true,
                    "clear": false
                },
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "command": "${fileDirname}/target/${fileBasenameNoExtension}.out",
                "linux": {
                    "command": "${fileDirname}/target/${fileBasenameNoExtension}.out"
                }
            }
        ]
    }
    ```

2. 这里可以通过``F1``按钮调出运行菜单，选择``Tasks: Build and Run``来选择在``tasks.json``中配置的多种任务指令。任务的名称和``lable``指定的相同。

3. 需要格外注意的是在``tasks.json``中存在多个任务后，``launch.json``中需要明确指定在执行debug前的前置任务是哪个，除非没有前置任务。

    ```Json
    "preLaunchTask": "build C++/python",
    ```
