#include "tinycom/vm.hpp"
#include "tinycommon/isa.hpp"
#include <iostream>

int main() {
	Tinycom::ISA::Init();
	Tinycom::VM vm;

	while (true) {
		vm.Update();
	}
	
	getchar();
	return 0;
}
