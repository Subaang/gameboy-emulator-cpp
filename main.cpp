#include <SFML/Graphics.hpp>
#include "Disassembler.h"
#include <iostream>

int main() {
    Disassembler disassembler{ "D:/C++/Gameboy Emulator/testROMS/cpu_instrs.gb" };
    disassembler.parseFile();
    disassembler.generateAssembly();
}
