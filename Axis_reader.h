#include  "ADC_reader.h"
#define X 0
#define Y 1

class Axis_reader : private ADC_reader{
    public:
        Axis_reader():ADC_reader(){};
        int read_axis(char axis);
};