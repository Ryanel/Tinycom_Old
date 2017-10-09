#pragma once
#include <cstdint>
#include <vector>
#include <queue>
#include <functional>
#include "tinycommon/priority_queue.hpp"

namespace Tinycom {
	class CPU;
	/**
	The main virtual machine. Coordinates time, simulates all hardware, and allows for communication between components.

	Either has a singlethreaded checkpoint system, or multithreaded checkpoint system
	*/

	class VM {
	private:
		/// Master clock of how many cycles have transpired
		uint64_t cycles = 0;
		uint64_t clockSpeed = 4000000; // 4mhz
		uint64_t checkpoint_divisor = 60; // To get 60fps

		uint64_t checkpoint_enforced_cycles_last = 0;
		uint64_t checkpoint_enforced_cycles = 100; // Enforce a checkpoint this many cycles.
		VM(const VM &obj);
		VM& operator=(const VM&); // no implementation


	public:
		VM();
		~VM();
		uint64_t GetCycles() { return cycles; }

		// Checkpoint system
		PriorityQueue<uint64_t> checkpoints;

		void AddCheckpoint(uint64_t cycle); // Deltas

		void OnCycle();
		void RunTillNextCheckpoint();
		void Update();

		// Devices that need to be included
		CPU * cpu;
	};
}
