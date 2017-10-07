set(tinyide_src
	main.cpp
)

add_executable(tinyide ${tinyide_src})
target_link_libraries(tinyide
	tiny_common
	${Boost_LIBRARIES}
)
