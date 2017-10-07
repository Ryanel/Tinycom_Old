set(tiny_common_src
	bytecode.cxx
	tokens.cxx
	dissassembly.cxx
)

add_library(tiny_common STATIC ${tiny_common_src})
