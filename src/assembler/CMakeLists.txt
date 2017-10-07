set(tinyasm_src
	main.cpp
)

add_executable(tinyasm ${tinyasm_src})
target_link_libraries(tinyasm tiny_common)
