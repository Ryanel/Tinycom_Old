#include "tinycom/instructions.hpp"
#include <stdio.h>
using namespace Tinycom;

int main() {

	tinycom_ins_t test;

	test.value = 0xABCD;
	test.reg_1 = 1;
	test.reg_2 = 2;
	test.opcode = 0xFE;
	printf("source: "); ISA::PrintInstruction(test);

	uint32_t result = ISA::EncodeInstruction(test);
	printf("encoded result: 0x%8X\n", result);

	tinycom_ins_t decompiled = ISA::DecodeInstruction(result);

	printf("decoded: "); ISA::PrintInstruction(decompiled);

	printf("re-encoded result: 0x%8X\n", ISA::EncodeInstruction(decompiled));

	getchar();
	return 0;
}