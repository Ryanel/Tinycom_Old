#include <cstring>
#include <cinttypes>
#include "tinycommon/isa.hpp"
#include "tinycom/vm.hpp"
#include "tinycom/cpu.hpp"

using namespace Tinycom;

CPU::CPU(VM * ctx) {
	vm = ctx;
	OnReset();
}

CPU::~CPU() {}

void CPU::OnReset() {
	memset(&r, 0, 0xF * sizeof(register_t)); // Clear all registers
}

void CPU::OnCycle() {
	// How much time do we have to make up for?
	cycleBudget = vm->GetCycles() - cycles;
	diag_lastBudget = cycleBudget;
	
	// Remove when memory implemented
	tinycom_ins_t test_nop = tinycom_ins_t();
	test_nop.opcode = 0x1;
	test_nop.reg_1 = 0x1;
	test_nop.reg_2 = 0xF;
	// Do actual work. Loops until we've run out of our cycle budget.
	diag_lastInstructions = 0;
	while (Execute(test_nop) != 0) {
		diag_lastInstructions++;
	};

	// Update diagnostic information
	diag_lastBehindCycles = cycleBudget;

	// Set cycles and return
	cycles = vm->GetCycles() - cycleBudget;
	Diag(3);
}

void CPU::Diag(int level) {
	if (level >= 1) {
		printf("cpu0: %" PRId64 " / %" PRId64 " cycles consumed from budget (%" PRId64 " behind, %" PRId64 " instructions)\n", diag_lastBudget - diag_lastBehindCycles, diag_lastBudget, diag_lastBehindCycles, diag_lastInstructions);
	}
	if (level >= 3) {
		printf("cpu0: |r0  = %04x |r1  = %04x |r2  = %04x |r3  = %04x |r4  = %04x |r5  = %04x |r6  = %04x|\n", r[0].val, r[1].val, r[2].val, r[3].val, r[4].val, r[5].val, r[6].val);
		printf("cpu0: |r7  = %04x |r8  = %04x |r9  = %04x |r10 = %04x |r11 = %04x |r12 = %04x |r13 = %04x|\n", r[7].val, r[8].val, r[9].val, r[10].val, r[11].val, r[12].val, r[13].val);
	}
	if (level >= 2) {
		printf("cpu0: |r14(sp)  = %04x                    |r15(pc)  = %04x \n", r[14].val, r[15].val);
	}
}
	

int CPU::Execute(uint32_t instruction)
{
	return Execute(ISA::DecodeInstruction(instruction));
}

/// Returns number of cycles used to execute.
int CPU::Execute(tinycom_ins_t instruction)
{
	int instruction_length = ISA::GetInstructionLength(instruction);
	int instruction_cycles = ISA::GetInstructionCycles(instruction);
	if (cycleBudget < instruction_cycles) {
		return 0;
	}

	cycleBudget -= instruction_cycles;

	// Increase PC, return
	r[reg_pc].val += instruction_length;
	return instruction_cycles;
}
