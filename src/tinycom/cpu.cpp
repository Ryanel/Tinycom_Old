#include "tinycommon/isa.hpp"
#include "tinycom/vm.hpp"
#include "tinycom/cpu.hpp"
#include <inttypes.h>


using namespace Tinycom;

CPU::CPU(VM * ctx)
{
	vm = ctx;
	cycles = 0;
}

CPU::~CPU() {}

void CPU::OnCycle() {
	// How much time do we have to make up for?
	uint64_t cycleBudget = vm->GetCycles() - cycles;
	// Do processing of x cycles. Overlap doesn't matter, as it's picked up next update.
	printf("cpu delta: %" PRIx64 "\n", cycleBudget);

	cycleBudget = 0; //FIXME: This simulates using every cycle.
	
	// Set cycles and return
	cycles = vm->GetCycles() - cycleBudget;
}
