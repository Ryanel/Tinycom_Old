#include "tinycommon/isa.hpp"
#include "tinycom/vm.hpp"

#include <stdio.h>
using namespace Tinycom;

int main() {
	tinycom_ins_t test;

	test.value = 0xFACE;
	test.reg_1 = 0xB;
	test.reg_2 = 0xB;
	test.opcode = 0xDA;
	printf("source: "); ISA::PrintInstruction(test);

	uint32_t result = ISA::EncodeInstruction(test);
	printf("encoded result: 0x%8X\n", result);

	tinycom_ins_t decompiled = ISA::DecodeInstruction(result);

	printf("decoded result: "); ISA::PrintInstruction(decompiled);

	printf("re-encoded result: 0x%8X\n", ISA::EncodeInstruction(decompiled));

	printf("instruction size: %d bytes\n", ISA::GetInstructionLength(decompiled));
	printf("instruction size: %d bytes\n", ISA::GetInstructionLength(result));
	getchar();
	return 0;
}
