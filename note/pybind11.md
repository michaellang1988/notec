# Pybind11 使用手册

## 安装方式

1. 使用git 直接clone.(如果是简单项目并不是很推荐)

2. 直接通过pip方式安装(小项目推荐)
'''shell
pip install pybind11 -i <https://pypi.tuna.tsinghua.edu.cn/simple> some-package
'''

## 使用方式

给个简单的cpp项目示例

1. 引入``pybind11``;
2. 使用``PYBIND11_MODULE``创建module.这里有个很坑的点,moudle入参必须为项目的名称，很多的示例里多没有标注这一点，很重要，会影响后续编译；

    ```c++
    #include <pybind11/pybind11.h>
    # include <Python.h>
    // template <typename T>
    // T add(T a, T b)
    // {
    //     return a + b;
    // }

    int add(int a, int b)
    {
        return a + b;
    }

    PYBIND11_MODULE(pyqc, m)
    {
        m.doc() = "pybind11 test";
        m.def("add", &add, "a add func");
    }
    ```

3. 然后使用命令进行编译

    ```bash
    # 项目名称为pyqc，必须要和源码中的module入参名称一样。。。
    # case1
    g++ -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` test.cpp -o pyqc -I /home/ez/miniconda3/include/python3.11

    #case2
    g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` test.cpp -o pyqc -I /home/ez/miniconda3/include/python3.11
    ```

4. 编译结束后会生成一个链接库文件，和项目名称相同。 但是这个无法直接使用，``python``导包会更具尾缀进行筛选， 需要重命名一下，增加``.so`` ,此处为``pyqc.so``.(这里很重要，同时需要将.so文件放入到python的导包路径中)

5. 可以在python中导入使用。

    ```python
    import pyqc
    print(pyqc.add(10, 20))
    ```

## 注意

虽然pybind11进行封装比手动通过``Python.h``进行封装，存在一定的性能损失，但是该封装过程简直比手动封装的方式好用太多。。。

## 官方文档

+ 中文文档： <https://charlottelive.github.io/pybind11-Chinese-docs/05.%E9%9D%A2%E5%AF%B9%E5%AF%B9%E8%B1%A1%E7%BC%96%E7%A8%8B.html>
+ github地址：<https://github.com/pybind/pybind11>
