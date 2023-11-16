#include "Axis_reader.h"
#include "Buttons.h"
#include "LCD_display.h"
#define X_POS 2
#define Y_POS 11
#define SPD_POS 44
#define TIK_POS 53
#define SPD_LMT 20
#define SPD_T_LMT 10
class Plane : private Axis_reader, Buttons, LCD_display{
    private:
        int axis_x, axis_y;
        int speed = 0;
        int speed_tick = 0;

    public:
        Plane();
        void update_axis();
        void update_speed();
        void update_speed_tick();
        void update_display();
        void run();
};