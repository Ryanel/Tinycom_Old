#include "tinycom/vm.hpp"
#include "tinycommon/isa.hpp"
#include "tinycommon/priority_queue.hpp"
using namespace Tinycom;

int main() {
	ISA::Init();
	VM vm;

	while (true) {
		vm.Update();
	}
	
	return 0;
}
