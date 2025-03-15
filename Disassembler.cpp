#include "Disassembler.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_map>

Disassembler::Disassembler(const std::string& filepath)
	: filepath(filepath) 
{

}

void Disassembler::parseFile() {

	std::ifstream inf{filepath,std::ios::binary};

	if (!inf) {
		std::cout << "Couldn't open ROM\n";
		exit(1);
	}

	uint8_t byte = 0;
	while (inf.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
		ROM.push_back(byte);
		std::cout << std::hex << static_cast<int>(byte) << "\n";
	}

	inf.close();

}

void Disassembler::disassemble() {
	//8 Bit opcodes
	

}