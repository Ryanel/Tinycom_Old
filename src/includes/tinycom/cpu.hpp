#pragma once
#include <cstdint>
#include "tinycom/hardware.hpp"
namespace Tinycom {
	/// A hardware register of width 16 bits
	typedef struct {
		struct {
			union {
				struct {
					uint8_t lo; ///< Low 8 bits of register
					uint8_t hi; ///< High 8 bits register
				};
				uint16_t val; ///< Full value of register
			};
		};
	} register_t;

	/// The Tinycom CPU
    class CPU : public Hardware {
		register_t regs[0xF];
	public:
		CPU(VM * ctx);
		~CPU();
		void OnCycle();
	};
}
