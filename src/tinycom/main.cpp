#include "tinycom/vm.hpp"
#include <iostream>

int main() {
	Tinycom::VM vm;
	vm.AddCheckpoint(1);
	//print_queue(vm.checkpoints);

	while (true) {
		vm.Update();
	}
	
	getchar();
	return 0;
}
