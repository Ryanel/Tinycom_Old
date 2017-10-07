
file(GLOB_RECURSE HEADERS ../includes/*.hpp)

set(tiny_common_src
	bytecode.cpp
	tokens.cpp
	dissassembly.cpp
	${HEADERS}
)

add_library(tiny_common STATIC ${tiny_common_src})
target_link_libraries(tiny_common ${Boost_LIBRARIES})
