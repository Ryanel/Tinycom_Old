#pragma once

#include <cstdint>

#define ISA_COND_EQ 0x0
#define ISA_COND_NE 0x1
#define ISA_COND_HS 0x2
#define ISA_COND_LO 0x3
#define ISA_COND_MI 0x4
#define ISA_COND_PL 0x5
#define ISA_COND_VS 0x6
#define ISA_COND_VC 0x7
#define ISA_COND_HI 0x8
#define ISA_COND_LS 0x9
#define ISA_COND_GE 0xA
#define ISA_COND_LT 0xB
#define ISA_COND_GT 0xC
#define ISA_COND_LE 0xD
#define ISA_COND_RS 0xE
#define ISA_COND_AL 0xF

/**
  An instruction on the tinycom.
  This is what the interpreter executes, but is converted from the compacted
  bytecode by the decoder.
*/
typedef struct tinycom_instruction {
    uint8_t opcode; ///< 0 - 256; operand, 8 bits
    uint8_t reg_1; ///< 4 bits
    uint8_t reg_2; ///< 4 bits
    uint16_t value; ///< The value used by the instruction, if needed. If present, the instruction is 32 bits long
} tinycom_ins_t;

namespace Tinycom {
	/// Container for anything to deal with the instruction set architecture of the Tinycom
	namespace ISA {
		void PrintInstruction(tinycom_ins_t ins); ///< Prints an intermediate representation of the tinycom_ins_t struct
		uint32_t EncodeInstruction(tinycom_ins_t ins); ///< Turns an instruction into a 32bit instruction.
		tinycom_ins_t DecodeInstruction(uint32_t ins); ///< Turns a 32bit instruction into a tinycom_ins_t struct (for easy parsing)

		// Opcode specific

		unsigned int GetInstructionLength(uint32_t a);
		unsigned int GetInstructionLength(tinycom_ins_t a);
	};
}
