#include "Plane.h"

int get_axis_X(Plane* pln){
    return pln->axis_x;
}

int get_axis_Y(Plane* pln){
    return pln->axis_y;
}

int get_speed(Plane* pln){
    return pln->speed;
}

int get_speed_tick(Plane* pln){
    return pln->speed_tick;
}

Plane::Plane():Buttons(),Axis_reader(),LCD_display(){
    set_cursor_position(0);
    Write('X'); Write(':');
    set_cursor_position(9);
    Write('Y'); Write(':');
    set_cursor_position(40);
    Write('S'); Write('P');Write('D');Write(':');
    set_cursor_position(49);
    Write('T'); Write('I');Write('K');Write(':');
}

void Plane::update_axis(){
    axis_x=read_axis(X);
    axis_y=read_axis(Y);
}

void Plane::update_speed(){
    if(read_button(SPEED_DOWN)){
        if((speed-speed_tick) < 0){
            speed = 0;
        }
        else{
            speed = speed - speed_tick;
        }
    }
    if(read_button(SPEED_UP)){
        if((speed+speed_tick)>SPD_LMT){
            speed = SPD_LMT;
        }
        else{
            speed = speed + speed_tick;
        }
    }
}

void Plane::update_speed_tick(){
    if(read_button(SPEED_TICK_DOWN)){
        if((speed_tick - 1) < 0){
            speed_tick = 0;
        }
        else{
            speed_tick = speed_tick - 1;
        }
    }
    if(read_button(SPEED_TICK_UP)){
        if((speed_tick + 1) > SPD_T_LMT){
            speed_tick = SPD_T_LMT;
        }
        else{
            speed_tick = speed_tick + 1;
        }
    }
}

void Plane::update_display(){
    set_cursor_position(X_POS);
    Write(axis_x);
    set_cursor_position(Y_POS);
    Write(axis_y);
    set_cursor_position(SPD_POS);
    Write(speed);
    set_cursor_position(TIK_POS);
    Write(speed_tick);
}

void Plane::run(){
    update_speed_tick();
    update_speed();
    update_axis();
    update_display();
}