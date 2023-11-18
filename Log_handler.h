#include "New_angle_ev.h"
#include "New_speed_ev.h"
#include "New_speedtick_ev.h"
#include "Plane.h"
#include "Queue.h"
class Log_handler{
    private:
        Queue<Event> Log;
        Plane past_pln;
    public:
        Log_handler();
        void update_log(Plane pln);
        void uart_send();
};
