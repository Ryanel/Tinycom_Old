set(tiny_common_src
	bytecode.cpp
	tokens.cpp
	dissassembly.cpp
)

add_library(tiny_common STATIC ${tiny_common_src})
