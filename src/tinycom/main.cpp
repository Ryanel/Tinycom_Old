#include "tinycom/vm.hpp"
int main() {
	Tinycom::VM vm;
	vm.SimulateCycles(10000000);
	return 0;
}
