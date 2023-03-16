#pragma once

#include "Bar.h"

class Land : public Bar {
public:
    Land();
    void touch(Character *character);
    ~Land();
};