#include <string>

namespace Tinycom {
	std::string ConditionMnemonic(char condition) {
		switch (condition)
		{
		case 0x0:
			return "EQ";
		case 0x1:
			return "NE";
		case 0x2:
			return "HS";
		case 0x3:
			return "LO";
		case 0x4:
			return "MI";
		case 0x5:
			return "PL";
		case 0x6:
			return "VS";
		case 0x7:
			return "VC";
		case 0x8:
			return "HI";
		case 0x9:
			return "LS";
		case 0xA:
			return "GE";
		case 0xB:
			return "LT";
		case 0xC:
			return "GT";
		case 0xD:
			return "LE";
		case 0xE:
			return "RS";
		case 0xF:
			return "AL";
		default:
			return "??";
		}
	}
}
