set(tinycom_src
	main.cxx
)

add_executable(tinycom ${tinycom_src})
target_link_libraries(tinycom tiny_common)
