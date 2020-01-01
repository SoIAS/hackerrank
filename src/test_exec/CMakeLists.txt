set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(
	text_exec_srcs
	main.cpp
)
add_executable(test_exec ${text_exec_srcs})
set_target_properties(test_exec PROPERTIES LINKER_LANGUAGE CXX)

if(ENABLE_COVERAGE)
	target_link_libraries(test_exec --coverage)
endif()

target_link_libraries(test_exec ipk_challenges)