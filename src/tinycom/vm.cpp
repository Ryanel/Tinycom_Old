#include <vector>
#include <queue>
#include <cstdio>
#include "tinycom/vm.hpp"
#include "tinycom/cpu.hpp"
#include "tinycom/mem.hpp"
using namespace Tinycom;

VM::VM() {
	cpu = new CPU(this);
	mem = new Memory();

	cpu->OnReset();

	cycles = 0;
	checkpoint_enforced_cycles_last = 0;


}
VM::~VM() {
	delete cpu;
	delete mem;
}

void VM::AddCheckpoint(uint64_t delta)
{
	checkpoints.push(delta + cycles);
}

void VM::OnCycle()
{
	cpu->OnCycle();
}

void VM::RunTillNextCheckpoint()
{
	if (checkpoints.empty()) { return; }
	cycles = checkpoints.top(); checkpoints.pop();
	OnCycle();
}

void VM::Update()
{
	// Force the system to continue running, by adding a checkpoint if none are around (which their should be)
	// This also enforces that there's a checkpoint in x cycles, always
	if (checkpoints.empty() || cycles > checkpoint_enforced_cycles + checkpoint_enforced_cycles_last) {
		checkpoint_enforced_cycles_last = cycles + checkpoint_enforced_cycles;
		AddCheckpoint(checkpoint_enforced_cycles);
	}
	RunTillNextCheckpoint();
}

