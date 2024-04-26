#include <string>
#include <vector>
#include <Python.h>
struct Pulse
{
    double amp;
    double freq;
    int time;
    std::string type_;

    Pulse(double amp, double freq, int time, std::string type_)
    {
        this->amp = amp;
        this->freq = freq;
        this->time = time;
        this->type_ = type_;
        this->_pulse.push_back(*this);
    }

    Pulse operator+(const Pulse &other_pulse)
    {
        _pulse.push_back(other_pulse);
    }
    void add_pulse(const Pulse &other_pulse)
    {
        _pulse.push_back(other_pulse);
    }

    // 获取脉冲列表
    std::vector<Pulse> get_pulses()
    {
        return _pulse;
    }

private:
    std::vector<Pulse> _pulse;
};

// 将 Pulse 结构体对象封装到 Python 的 Capsule 中
static PyObject *pulse_new(PyObject *self, PyObject *args)
{
    double amp, freq;
    int time;
    const char *type;
    if (!PyArg_ParseTuple(args, "ddis", &amp, &freq, &time, &type))
    {
        return nullptr;
    }
    Pulse *pulse = new Pulse(amp, freq, time, std::string(type));
    PyObject *capsule = PyCapsule_New(pulse, nullptr, nullptr);
    return capsule;
}

// 销毁 Pulse 结构体对象
static void pulse_dealloc(PyObject *capsule)
{
    Pulse *pulse = (Pulse *)PyCapsule_GetPointer(capsule, nullptr);
    delete pulse;
}

// 将 Pulse 结构体对象的公共方法封装到 Python 中
static PyObject *pulse_add_pulse(PyObject *self, PyObject *args)
{
    Pulse *pulse;
    Pulse *other_pulse;
    PyObject *pulse_capsule;
    PyObject *other_pulse_capsule;
    if (!PyArg_ParseTuple(args, "OO", &pulse_capsule, &other_pulse_capsule))
    {
        return nullptr;
    }
    pulse = (Pulse *)PyCapsule_GetPointer(pulse_capsule, nullptr);
    other_pulse = (Pulse *)PyCapsule_GetPointer(other_pulse_capsule, nullptr);
    pulse->add_pulse(*other_pulse);
    Py_RETURN_NONE;
}

// 获取 Pulse 结构体对象的脉冲列表
static PyObject *pulse_get_pulses(PyObject *self, PyObject *args)
{
    Pulse *pulse;
    PyObject *pulse_capsule;
    if (!PyArg_ParseTuple(args, "O", &pulse_capsule))
    {
        return nullptr;
    }
    pulse = (Pulse *)PyCapsule_GetPointer(pulse_capsule, nullptr);
    std::vector<Pulse> pulses = pulse->get_pulses();
    PyObject *pulse_list = PyList_New(pulses.size());
    for (size_t i = 0; i < pulses.size(); ++i)
    {
        PyObject *pulse_obj = Py_BuildValue("(ddis)", pulses[i].amp, pulses[i].freq, pulses[i].time, pulses[i].type_.c_str());
        PyList_SetItem(pulse_list, i, pulse_obj);
    }
    return pulse_list;
}

// 定义模块方法列表
static PyMethodDef pulse_methods[] = {
    {"add_pulse", pulse_add_pulse, METH_VARARGS, "Add another pulse to the pulse list."},
    {"get_pulses", pulse_get_pulses, METH_VARARGS, "Get the list of pulses."},
    {nullptr, nullptr, 0, nullptr}};
