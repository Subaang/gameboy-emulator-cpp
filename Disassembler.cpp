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
	}

	inf.close();

}

void Disassembler::generateAssembly(){
	for (int i = 0; i < ROM.size(); i++) {
		Instruction instr = lookupTable8Bit[ROM[i]];

		if (instr.opcode == "PREFIX") {
			i++;
			instr = lookupTable16Bit[ROM[i]];
			assemblyCode.push_back(instr);

		}
		else {
			char buffer[7];
			
			if (instr.operand2 == "d8" || instr.operand2 == "a8" || instr.operand2 == "s8") {
				snprintf(buffer, sizeof(buffer), "%02X", ROM[i + 1]); // %02X forces 0A instead of just A
				instr.operand2 = buffer;
				i++;
			}
			else if (instr.operand1 == "s8") {
				snprintf(buffer, sizeof(buffer), "%02X", ROM[i + 1]);
				instr.operand1 = buffer;
				i++;
			}
			else if (instr.operand2 == "d16" || instr.operand2 == "a16") {
				snprintf(buffer, sizeof(buffer), "%02X%02X", ROM[i + 2], ROM[i + 1]); 
				instr.operand2 = buffer;
				i += 2;
			}
			else if (instr.operand1 == "a16") {
				snprintf(buffer, sizeof(buffer), "%02X%02X", ROM[i + 2], ROM[i + 1]);
				instr.operand1 = buffer;
				i += 2;
			}
			else if (instr.operand1 == "(a8)") {
				snprintf(buffer, sizeof(buffer), "(%02X)", ROM[i + 1]); 
				instr.operand1 = buffer;
				i++;
			}
			else if (instr.operand1 == "(a16)") {
				snprintf(buffer, sizeof(buffer), "(%02X%02X)", ROM[i + 2], ROM[i + 1]);
				instr.operand1 = buffer;
				i += 2;
			}
			else if (instr.operand2 == "(a8)") {
				snprintf(buffer, sizeof(buffer), "(%02X)", ROM[i + 1]);
				instr.operand2 = buffer;
				i++;
			}
			else if (instr.operand2 == "(a16)") {
				snprintf(buffer, sizeof(buffer), "(%02X%02X)", ROM[i + 2], ROM[i + 1]);
				instr.operand2 = buffer;
				i += 2;
			}
			else if (instr.operand2 == "SP+s8") {
				snprintf(buffer, sizeof(buffer), "SP+%02X", ROM[i + 1]);
				instr.operand2 = buffer;
				i++;
			}

			

			assemblyCode.push_back(instr);
		}
	}

	for (auto i : assemblyCode) {
		if (i.opcode != "NOP") {
			std::cout << i.opcode << " " << i.operand1 << " " << i.operand2 << "\n";
		}
		if (i.opcode == "INVALID") {
			std::cout << "-----------------------------------------\n";
		}
		
	}
}