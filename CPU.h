#pragma once
#include <stdint.h>
#include <string>
#include <variant>
#include "Instruction.h"

class CPU
{
private:
    // Registers
    uint8_t A,B,C,D,E,H,L;
    uint16_t SP, PC;

    // Flag Registers - These are lower 4 bits of AF
    uint8_t z, n, h, c; // Zero, Subtraction, Half Carry, Carry


    int t_cycles{ 0 };

public:

    template<typename T>
    void setFlag(T& flag, int val) {
        flag = val;
    }

    template<typename T>
    int getFlag(T& flag) {
        return flag;
    }

    void executeInstruction(Instruction* instruction);

};
