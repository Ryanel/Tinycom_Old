#pragma once
#include <cstdint>
#include "tinycom/hardware.hpp"
#include "tinycommon/isa.hpp"
namespace Tinycom {
	class Memory {
	private:
		inline uint32_t sanitize_address(uint32_t address) {
			return address & 0xFFFFFF;
		}
	public:
		uint8_t  Read8   (uint32_t address);
		uint16_t Read16  (uint32_t address);
		uint32_t Read32  (uint32_t address);
		uint64_t Read64  (uint32_t address);
		void     Write8  (uint32_t address, uint8_t  value);
		void     Write16 (uint32_t address, uint16_t value);
		void     Write32 (uint32_t address, uint32_t value);
		void     Write64 (uint32_t address, uint64_t value);
	};
}
