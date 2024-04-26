# rust开发python扩展

目前rust开发python扩展比较主流的是采用pyo3这个库来实现rust -> python. 目前qiskit中也是使用的该库。

创建项目的方式有两种:
+ 一种是直接创建 rust的lib项目，导入pyo3开发三方库。然后通过编译，将编译的lib文件放到项目同级目录或者site-package中可以识别。切记lib名称和设置扩展名称要一致，否则无法导入。(cargo里面这个设定很抽象，即使设置了编译生成的名称，还是会在生成的名称前面加上一个lib...)。
+ 另外一种是通过python的三方库`` maturin``来创建rust项目以及编译打包的工作。该库也是pyo3提供的官方工具。

## tips

简单的项目推荐使用 ``maturin``来创建，真的很便捷！！！

## maturin
使用maturin必须使用conda环境或者虚拟环境。无法在原生环境下使用该功能。

1. 创建项目
```
maturin init xxx(包名称)
```

2. 编译调式
该命令会编译rust项目，并将生成的rustlib文件打包成包，直接安装到当前的python环境中，后续可以直接使用pip操作。
```
maturin develop
```

3. 打包
```
#打包并推送发布到pypi上。
maturin build

# 打包不推送
maturin build -f
```