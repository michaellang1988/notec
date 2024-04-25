#include <msgpack.hpp>
#include <string>
#include <iostream>
#include <msgpack.hpp>
void test_msgpack()
{
    // 序列化
    msgpack::sbuffer sbuf;

    msgpack::packer<msgpack::sbuffer> pker(&sbuf);

    pker.pack_map(3);

    pker.pack(std::string("type"));
    pker.pack(3);

    pker.pack(std::string("ratio"));
    pker.pack(2.14);

    pker.pack(std::string("msg"));
    pker.pack(std::string("catkit"));

    // 反序列化
    msgpack::object_handle oh;

    // 使用 msgpack::unpack，将结果存储在 msgpack::object_handle 中
    msgpack::unpack(oh, sbuf.data(), sbuf.size());
    std::cout << sbuf.data() << std::endl;

    // 提取 msgpack::object，以便访问序列化数据
    // const msgpack::object &obj = oh.get();

    // 使用 msgpack::object 的方法访问数据
    // ...（此处省略访问obj的具体逻辑）
}