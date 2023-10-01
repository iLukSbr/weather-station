/* Component */

#pragma once

#include "pch.h"

#define START_TRIES 3// Attempts to start sensor
#define LOOP_DELAY 100// (ms) Delay between start attempts

class Component{
    protected:
        bool started;
    
    public:
        Component();
        virtual ~Component();

        bool isStarted() const;

        virtual void print() const = 0;
        virtual void read() = 0;
        virtual void start() = 0;      
};