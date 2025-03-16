#pragma once

enum class Opcode {
    LD,
    LDH,
    ADC,
    ADD,
    CP,
    DEC,
    INC,
    SBC,
    SUB,
    AND,
    CPL,
    OR,
    XOR,
    BIT,
    RES,
    SET,
    RL,
    RLA,
    RLC,
    RLCA,
    RR,
    RRA,
    RRC,
    RRCA,
    SLA,
    SRA,
    SRL,
    SWAP,
    CALL,
    JP,
    JR,
    RET,
    RETI,
    RST,
    CCF,
    SCF,
    POP,
    PUSH,
    DI,
    EI,
    HALT,
    DAA,
    NOP,
    STOP,
    PREFIX,
    INVALID

};

struct Instruction {
    Opcode opcode;
    //std::string opcode;
    std::string operand1;
    std::string operand2;
};