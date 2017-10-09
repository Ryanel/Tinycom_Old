#include "tinycommon/isa.hpp"
#include <stdio.h>

namespace Tinycom {
	namespace ISA {
		
		tinycom_ins_def_t instructions[0xFF] = {};
		void Init() {
			// Init instruction data. Could be baked
			// Only exceptions to defaults are located here
			// The defaults are a length of 4, cycles of 1
			// Format: Cycles, Length
			instructions[0x00] = { 1, 1 }; // NOP

			instructions[0x01] = { 4, 4 }; // INC R
			instructions[0x02] = { 8, 4 }; // INC $
			instructions[0x03] = { 8, 4 }; // INC $ + R
			instructions[0x11] = { 4, 2 }; // DEC R
			instructions[0x12] = { 8, 4 }; // DEC $
			instructions[0x13] = { 8, 4 }; // DEC $ + R
		}

		void PrintInstruction(tinycom_ins_t ins) {
			printf("[%02x:%d-%d=%04x]\n", ins.opcode, ins.reg_1, ins.reg_2, ins.value);
		}

		uint32_t EncodeInstruction(tinycom_ins_t ins) {
			uint32_t bytecode = ins.opcode << 24;
			uint32_t reg_1 = (ins.reg_1 & 0xF) << 20;
			uint32_t reg_2 = (ins.reg_2 & 0xF) << 16;
			uint32_t value = ins.value;
			bytecode = bytecode | reg_1 | reg_2 | value;
			return bytecode;
		}

		tinycom_ins_t DecodeInstruction(uint32_t ins) {
			tinycom_ins_t decode;
			decode.opcode = (ins & 0xFF000000) >> 24;
			decode.reg_1 = (ins & 0x00F00000) >> 20;
			decode.reg_2 = (ins & 0x000F0000) >> 16;
			decode.value = (ins & 0x0000FFFF);
			return decode;
		}

		uint8_t GetInstructionOpcode(uint32_t ins) {
			return (ins & 0xFF000000) >> 24;
		}


		// Undecoded wrappers
		unsigned int GetInstructionLength(uint32_t a) {
			return GetInstructionLength(DecodeInstruction(a));
		}
		unsigned int GetInstructionCycles(uint32_t a) {
			return GetInstructionCycles(DecodeInstruction(a));
		}


		unsigned int GetInstructionLength(tinycom_ins_t a) {
			int length = instructions[a.opcode].length;
			if (length == 0) { length = 4; }
			return length;
		}
		unsigned int GetInstructionCycles(tinycom_ins_t a)
		{
			int cycles = instructions[a.opcode].cycles;
			if (cycles == 0) { cycles = 1; }
			return cycles;
		}
		
	}
	
}
