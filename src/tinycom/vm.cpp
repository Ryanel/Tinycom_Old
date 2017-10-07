#include "tinycom/vm.hpp"
#include "tinycom/cpu.hpp"
#include <vector>
#include <queue>
#include <inttypes.h>
#include <cstdio>
using namespace Tinycom;

VM::VM() {
	cpu = new CPU(this);
}
VM::~VM() {
	delete cpu;
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
	cycles = checkpoints.top();
	checkpoints.pop();

	printf("checkpoint: %" PRIx64 "\n", cycles);

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
	
	// TODO: Sleep if we were under budget
	/*
	if(cycles < sleep_last_cycles + deltaCyclesTillNextSleep) {
		// Use a timer from the start of the loop, to now, to determine deltaTime < (1 / checkpoint_divisor)
		// usleep(deltaTime)
	}
	*/
}

