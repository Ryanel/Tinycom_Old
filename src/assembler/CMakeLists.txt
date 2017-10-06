set(tinyasm_src
	main.cxx
)

add_executable(tinyasm ${tinyasm_src})
target_link_libraries(tinyasm tiny_common)
