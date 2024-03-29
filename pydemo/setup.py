from distutils.core import setup, Extension


def main():
    setup(
        name="myextension",
        version="1.0.0",
        description="abc",
        author="abc",
        author_email="abc",
        ext_modules=[
            Extension(
                "myextension",
                sources=["py_main.cpp"],
                # include_dirs=["头文件目录，这里填当前目录即可"],
                # libraries=["mathfunlib"],
                # library_dirs=["库文件目录，这里填当前目录即可"],
                language="c++",
                extra_compile_args=["-std=c++11"],
            )
        ],
    )


if __name__ == "__main__":
    main()
