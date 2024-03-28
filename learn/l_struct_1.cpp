#include <string>
#include <iostream>
struct Pulse
{
    int amp;
    int freq;
    std::string type;

private:
    int _temp_data;

public:
    Pulse(int amp, int freq)
    {
        this->amp = amp;
        this->freq = freq;
    }

    /* data */

    // Pulse operator+(const Pulse &base_pulse)
    // {
    //     return {amp + base_pulse.amp, freq + base_pulse.freq};
    // }
    Pulse operator+(const Pulse &base_pulse)
    {
        amp += base_pulse.amp;
        freq += base_pulse.freq;
        return *this;
    }
};

void test_pulse()
{
    Pulse p1(10, 2), p2(20, 3);

    p1.type = "bame";

    std::cout << "test pulse" << (p1 + p2).type << std::endl;
    std::cout << "test pulse" << (p1 + p2).amp << std::endl;
}