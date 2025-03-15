#include <SFML/Graphics.hpp>
#include "Disassembler.h"
#include <iostream>

int main() {
    Disassembler disassembler{ "D:/C++/Gameboy Emulator/testROMS/pokemon_red.gb" };
    disassembler.parseFile();
}
