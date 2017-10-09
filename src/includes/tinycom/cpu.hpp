#pragma once
#include <cstdint>
#include "tinycom/hardware.hpp"
#include "tinycommon/isa.hpp"
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
		register_t r[16];
		uint64_t cycleBudget = 0;

		uint64_t diag_lastBehindCycles = 0;
		uint64_t diag_lastBudget = 0;
		uint64_t diag_lastInstructions = 0;

	public:
		const int reg_pc = 0xF;

		explicit CPU(VM * ctx);
		~CPU();
		void OnReset();
		void OnCycle();
		void Diag(int level);
		int Execute(uint32_t instruction);
		int Execute(tinycom_ins_t instruction);
	};
}
