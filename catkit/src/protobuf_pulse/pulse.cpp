#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "pulse.pb.h"
// struct PulseComponent
// {
//     std::string type_;
//     double time;
//     std::vector<PulseComponent> _pulse;
//     bool _fake_pulse;

//     PulseComponent(double time, std::string type_) : time(time) {}

//     PulseComponent __add__(const PulseComponent &other_pulse)
//     {
//         this->_pulse.push_back(other_pulse);
//     }
// };

void test()
{
    Drag darg;
    darg.set_amp(0.1);
    darg.set_detune(0.2);
    std::cout << "Darg" << darg.amp() << std::endl;

    std::ofstream output("darg.bin", std::ios::binary);
    if (!darg.SerializeToOstream(&output))
    {
        std::cerr << "Failed to serialize person data." << std::endl;
        return;
    }
    output.close();
};

int main(){
    test();
    return 0;
}