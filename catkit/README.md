# Catkit

catkit是用来学习c++ 和 python混合开发，编译打包的项目

## 编译

1. 首先运行编译c++模块

```shell
python setup.py build
```

2. 如果测试可以使用pip命令直接安装到当前环境

```shell
pip install .
```

3. 如果需要打包为wheel环境，可以使用如下命令

```shell
python setup.py bdist_wheel
```
