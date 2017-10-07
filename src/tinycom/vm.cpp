#include "tinycom/vm.hpp"
using namespace Tinycom;

void VM::SimulateCycles(uint64_t cycles) {
	// FIXME: This is a naive, SLOW, implementation.
	// Implement a checkpoint system, in which VM fastforwards x cycles to next event.
	for (cycles; cycles > 0; cycles--) {
		OnCycle();
		this->cycles++;
	}
}

void VM::OnCycle() {

}
