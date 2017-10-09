#include "tinycom/mem.hpp"
using namespace Tinycom;

uint8_t Memory::Read8(uint32_t address)
{
	address = sanitize_address(address);
	return uint8_t();
}

uint16_t Memory::Read16(uint32_t address)
{
	address = sanitize_address(address);
	return uint8_t();
}

uint32_t Memory::Read32(uint32_t address)
{
	address = sanitize_address(address);
	return uint8_t();
}

uint64_t Memory::Read64(uint32_t address)
{
	address = sanitize_address(address);
	return uint8_t();
}

void Memory::Write8(uint32_t address, uint8_t value)
{
	address = sanitize_address(address);
}

void Memory::Write16(uint32_t address, uint16_t value)
{
	address = sanitize_address(address);
}

void Memory::Write32(uint32_t address, uint32_t value)
{
	address = sanitize_address(address);
}
void Memory::Write64(uint32_t address, uint64_t value)
{
	address = sanitize_address(address);
}