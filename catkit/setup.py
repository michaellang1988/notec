#!/usr/bin/env python

import os
import sys
from setuptools import setup, Extension, find_packages
import pybind11

# 获取当前目录
here = os.path.abspath(os.path.dirname(__file__))


# 指定扩展模块
example_module = Extension(
    "catkit.example",
    sources=["src/example_module.cpp"],
    include_dirs=[pybind11.get_include(), "src"],
    language="c++",
    extra_compile_args=["-std=c++11"],  # 或使用其他合适的C++标准
)

pulse_module = Extension(
    "catkit._protobuf_pulse",
    sources=["src/protobuf_pulse/pulse_module.cpp"],
    include_dirs=[
        pybind11.get_include(),
        "src/protobuf_pulse",
    ],
    language="c++",
    extra_compile_args=[
        "-std=c++11",
        "-lpthread",
        "-lprotobuf",
    ],  # 或使用其他合适的C++标准
)

msgpack_module = Extension(
    "catkit._msgpack_pulse",
    sources=["src/msgpackpulse/module_msgpulse.cpp"],
    include_dirs=[
        pybind11.get_include(),
        "src/msgpackpulse",
        "/opt/vcpkg/installed/x64-linux/include",
    ],
    language="c++",
    extra_compile_args=["-std=c++11"],  # 或使用其他合适的C++标准
)
# setup函数参数
setup(
    name="catkit",
    version="0.1",
    author="Your Name",
    author_email="your.email@example.com",
    description="A mixed C++/Python library using pybind11",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    # url='https://github.com/yourusername/example_library',
    ext_modules=[example_module, pulse_module, msgpack_module],
    packages=find_packages(),  # 包含example_interface.py的包名
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.7",  # 支持的Python最低版本
)
