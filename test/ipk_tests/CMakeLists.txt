file(GLOB SRCS *.cpp)

add_executable(ipk_tests ${SRCS})

target_link_libraries(
	ipk_tests
	ipk_challenges
	gtest
	gmock_main
)

if(ENABLE_COVERAGE)
	target_link_libraries(ipk_tests --coverage)
endif()

install(TARGETS ipk_tests DESTINATION bin)
add_test(UnitTests ipk_tests)