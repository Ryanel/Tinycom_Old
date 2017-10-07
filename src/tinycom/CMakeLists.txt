set(tinycom_src
	main.cpp
	vm.cpp
	cpu.cpp
	ppu.cpp
)

add_executable(tinycom ${tinycom_src})
target_link_libraries(tinycom
	tiny_common
	${Boost_LIBRARIES}
)
