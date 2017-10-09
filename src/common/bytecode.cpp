#include "tinycommon/isa.hpp"
#include <stdio.h>

namespace Tinycom {
	namespace ISA {

		static tinycom_ins_def_t instructions[0xFF] = {};
		void Init() {
			// Init instruction data. Could be baked
			// Only exceptions to defaults are located here
			// The defaults are a length of 4 bytes, cycles of 4
			// Format: Cycles, Length
			instructions[0x00] = { 1, 1 }; // NOP

			instructions[0x01] = { 4, 2 }; // INC R
			instructions[0x02] = { 8, 5 }; // INC $
			instructions[0x03] = { 8, 5 }; // INC $ + R
			instructions[0x11] = { 4, 2 }; // DEC R
			instructions[0x12] = { 8, 5 }; // DEC $
			instructions[0x13] = { 8, 5 }; // DEC $ + R
		}

		void PrintInstruction(tinycom_ins_t ins) {
			printf("[%02x:%x-%x=%04x]\n", ins.opcode, ins.reg_1, ins.reg_2, ins.value);
		}

		tinycom_ins_enc_t EncodeInstruction(tinycom_ins_t ins) {
			tinycom_ins_enc_t bytecode = (tinycom_ins_enc_t)ins.opcode << 56;
			tinycom_ins_enc_t reg_1 = (tinycom_ins_enc_t)(ins.reg_1 & 0xF) << 52;
			tinycom_ins_enc_t reg_2 = (tinycom_ins_enc_t)(ins.reg_2 & 0xF) << 48;
			tinycom_ins_enc_t value = (tinycom_ins_enc_t)(ins.value & 0xFFFFFF) << 24;
			bytecode = bytecode | reg_1 | reg_2 | value;
			return bytecode;
		}

		tinycom_ins_t DecodeInstruction(tinycom_ins_enc_t ins) {
			tinycom_ins_t decode;
			decode.opcode = (ins & 0xFF00000000000000) >> 56;
			decode.reg_1 =  (ins & 0x00F0000000000000) >> 52;
			decode.reg_2 =  (ins & 0x000F000000000000) >> 48 ;
			decode.value =  (ins & 0x0000FFFFFF000000) >> 24 ;
			return decode;
		}

		uint8_t GetInstructionOpcode(uint32_t ins) {
			return (ins & 0xFF00000000000000) >> 56;
		}


		// Undecoded wrappers
		unsigned const int GetInstructionLength(tinycom_ins_enc_t a) {
			return GetInstructionLength(DecodeInstruction(a));
		}
		unsigned const int GetInstructionCycles(tinycom_ins_enc_t a) {
			return GetInstructionCycles(DecodeInstruction(a));
		}


		unsigned const int GetInstructionLength(tinycom_ins_t a) {
			return instructions[a.opcode].length;;
		}
		unsigned const int GetInstructionCycles(tinycom_ins_t a)
		{
			return instructions[a.opcode].cycles;
		}
	}
}
