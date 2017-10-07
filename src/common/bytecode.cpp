#include "tinycommon/instructions.hpp"
#include <stdio.h>

namespace Tinycom
{
	void ISA::PrintInstruction(tinycom_ins_t ins) {
		printf("[%02x:%d-%d=%04x]\n", ins.opcode, ins.reg_1, ins.reg_2, ins.value);
	}

	uint32_t ISA::EncodeInstruction(tinycom_ins_t ins) {
		uint32_t bytecode = ins.opcode << 24;

		uint32_t reg_1 = (ins.reg_1 & 0xF) << 20;
		uint32_t reg_2 = (ins.reg_2 & 0xF) << 16;
		uint32_t value = ins.value;

		bytecode = bytecode | reg_1 | reg_2 | value;

		return bytecode;
	}

	tinycom_ins_t ISA::DecodeInstruction(uint32_t ins) {
		tinycom_ins_t decode;
		uint32_t opcode = (ins & 0xFF000000) >> 24;
		uint32_t reg_1 = (ins & 0x00F00000) >> 20;
		uint32_t reg_2 = (ins & 0x000F0000) >> 16;
		uint32_t value = (ins & 0x0000FFFF) ;

		decode.opcode = opcode;
		decode.reg_1 = reg_1;
		decode.reg_2 = reg_2;
		decode.value = value;
		return decode;
	}

}
