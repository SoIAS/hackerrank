set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(
	ipk_srcs
	ipk_warm_up.cpp
	ipk_warm_up.h
)
add_library(ipk_challenges STATIC ${ipk_srcs})
set_target_properties(ipk_challenges PROPERTIES LINKER_LANGUAGE CXX)

if(ENABLE_COVERAGE)
	target_link_libraries(ipk_challenges --coverage)
endif()

target_include_directories(ipk_challenges PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})