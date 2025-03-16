#include "CPU.h"
#include "Instruction.h"
#include <cstdlib>


void CPU::executeInstruction(Instruction* instr)
{
	switch(instr->opcode) {
		case(Opcode::ADC):
			//First operand of ADC is always A
			if (instr->operand2 == "A") {
				A += A + c;
			}
			else if (instr->operand2 == "B") {
				A += B + c;
			}
			else if (instr->operand2 == "C") {
				A += C + c;
			}
			else if (instr->operand2 == "D") {
				A += D + c;
			}
			else if (instr->operand2 == "E") {
				A += E + c;
			}
			else if (instr->operand2 == "H") {
				A += H + c;
			}
			else if (instr->operand2 == "L") {
				A += L + c;
			}
			else if (instr->operand2 == "(HL)") {
				uint16_t HL = (H << 8) | L;
				//A += memory[HL] + c
			}


		
	}
}
