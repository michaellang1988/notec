# c++包管理

c++没有官方和社区的包管理软件,受限于c++的诞生年份，这点比不了后诞生的高级语言一点。而且网络上不同的三方库的安装调用方式也很千奇百怪。

## VCPKG

vcpkg是微软在创建的一个c++三方依赖管理工具，收集了部分c++的三方库，对于windows的开发而言十分便利，同时ubuntu环境下也是可以安装的。

### windows安装

<https://learn.microsoft.com/zh-cn/vcpkg/get_started/overview>

### ubuntu安装

<https://lindevs.com/install-vcpkg-on-ubuntu/>

```txt
Prepare environment
Make sure you have installed Git in your system. You can read post how to install it.

Also, you need to install zip and unzip packages:

sudo apt update
sudo apt install -y zip unzip
For libraries compilation, you need to install build-essential and pkg-config packages:

sudo apt install -y build-essential pkg-config
Install vcpkg
Download vcpkg from GitHub repository:

wget -qO vcpkg.tar.gz <https://github.com/microsoft/vcpkg/archive/master.tar.gz>
Create a new directory to store vcpkg and extract the tar.gz file to it:

sudo mkdir /opt/vcpkg
sudo tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg
Run the following command to build vcpkg itself:

sudo /opt/vcpkg/bootstrap-vcpkg.sh
In /usr/local/bin directory, we can create a symbolic link to the vcpkg command:

sudo ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg
Now vcpkg can be used as a system-wide command for all users. We can check vcpkg version with command:

vcpkg version
The tar.gz file is no longer needed, remove it:

rm -rf vcpkg.tar.gz
```

### 仓库地址

+ 默认存放在 ``~/.vcpkg/installed/``
+ 目前安装存放在``/opt/vcpkg/installed/x64-linux/include``
