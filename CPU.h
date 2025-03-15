#pragma once
#include <stdint.h>
#include <string>
#include <variant>
class CPU
{
private:
    // Registers
    uint16_t AF, BC, DE, HL, SP, PC;

    // Flag Registers
    uint8_t z, n, h, c; // Zero, Subtraction, Half Carry, Carry

public:

    template<typename T>
    void setFlag(T& flag, int val) {
        flag = val;
    }

    template<typename T>
    int getFlag(T& flag) {
        return flag;
    }

};
