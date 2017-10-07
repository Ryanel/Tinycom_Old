#pragma once
#include <cstdint>

namespace Tinycom {
    class VM {
    private:
        uint64_t cycles;
	public:
		/// Runs x amount of cycles
		void SimulateCycles(uint64_t cycles);
		/// Simulates the whole machine's work over a single cycle
		void OnCycle();
    };
}
