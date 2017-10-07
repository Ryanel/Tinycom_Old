#pragma once
#include <cstdint>

namespace Tinycom {
	class VM;
    class Hardware {
	protected:
		VM * vm;
		uint64_t cycles;
    public:
        virtual void OnCycle() {};
    };
}
