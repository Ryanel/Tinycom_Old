#pragma once
#include <cstdint>

namespace Tinycom {
	class VM;
	/**
	Hardware inside of the VM.

	Hardware can experience time, just like in a physical computer. 
	All components are executed in a well ordered manner, one at a time, but in the real world, they run all at once.
	This class allows the basics of hardware being able to experience time, and catch up or run in parralel as they choose.
	*/
    class Hardware {
	protected:
		VM * vm; ///< Reference to the VM that this hardware is apart of (for communication)
	public:
		uint64_t cycles; ///< Interal reference of how many cycles of time this piece of hardware has experienced.
    
		/// For each cycle that's relevant (been checkpointed), called by the VM.
        virtual void OnCycle() = 0;
    };
}
