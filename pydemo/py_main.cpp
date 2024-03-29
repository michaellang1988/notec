#include <Python.h>
#include <stddef.h>
// 定义一个 C++ 函数，用于相加两个整数
int add(int a, int b)
{
    return a + b;
}

// 定义一个 Python C 扩展函数，将两个整数相加
static PyObject *py_add(PyObject *self, PyObject *args)
{
    int a, b;
    // 从 Python 中获取两个整数参数
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return nullptr;
    }
    // 调用 C++ 函数进行相加
    int result = add(a, b);
    // 将结果转换为 Python 对象并返回
    return PyLong_FromLong(result);
}

struct Point
{
    int x;
    int y;

    Point(int a, int b)
    {
        this->x = a;
        this->y = b;
    }

    Point operator+(const Point &other_point)
    {
        this->x += other_point.x;
        this->y += other_point.y;
        return *this;
    }

    int get_x()
    {
        return x;
    }
};

// 创建 Point 结构体对象
static PyObject *Point_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Point *self;
    self = (Point *)type->tp_alloc(type, 0);
    if (self != nullptr)
    {
        self->x = 0;
        self->y = 0;
    }
    return (PyObject *)self;
}

// 销毁 Point 结构体对象
static void Point_dealloc(Point *self)
{
    Py_TYPE(self)->tp_free((PyObject *)self);
}

// 设置 Point 结构体的属性
static int Point_init(Point *self, PyObject *args, PyObject *kwds)
{
    static char *keywords[] = {"x", "y", nullptr};
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ii", keywords, &(self->x), &(self->y)))
    {
        return -1;
    }
    return 0;
}

// 定义 Point 结构体的属性列表
// static PyMemberDef Point_members[] = {
//     {"x", PyLong_Type, offsetof(Point, x), 0, "X coordinate"},
//     {"y", PyLong_Type, offsetof(Point, y), 0, "Y coordinate"},
//     {nullptr}};

// 定义 Point 结构体的方法列表
static PyMethodDef Point_methods[] = {
     {nullptr, nullptr, 0, nullptr}};

// 定义 Point 结构体的类型对象
static PyTypeObject PointType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
        .tp_name = "point.Point",
    .tp_basicsize = sizeof(Point),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor)Point_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Point objects",
    .tp_methods = Point_methods,
    // .tp_members = Point_members,
    .tp_init = (initproc)Point_init,
    .tp_new = Point_new,
};

// 定义模块方法列表
static PyMethodDef methods[] = {
    // {"Python中调用的函数名", 对应的 C 扩展函数, METH_VARARGS 标志, 函数描述}
    {"add", py_add, METH_VARARGS, "Add two integers."},
    // 方法列表必须以 {nullptr, nullptr, 0, nullptr} 结尾
    {nullptr, nullptr, 0, nullptr}};

// 定义模块初始化函数
static struct PyModuleDef module = {
    // 模块的基本信息
    PyModuleDef_HEAD_INIT,
    // 模块名
    "myextension",
    // 模块文档
    "A simple example module.",
    // 模块内存占用，如果不使用全局变量，填 0
    -1,
    // 模块方法列表
    methods};

// 初始化模块
PyMODINIT_FUNC PyInit_myextension(void)
{
    PyObject *m = PyModule_Create(&module);
    if (m == nullptr)
    {
        return nullptr;
    }

    Py_INCREF(&module);
    PyModule_AddObject(m, "Point", (PyObject *)&PointType);
    // 返回一个新的模块对象
    return m;
}
