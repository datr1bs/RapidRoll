#pragma once

#include "Bar.h"

class Trap : public Bar {
public:
    Trap();
    void touch(Character *character);
    ~Trap();
};