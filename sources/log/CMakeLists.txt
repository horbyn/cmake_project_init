file(GLOB SOURCES *.cc *.hpp)
add_library(log ${SOURCES})
target_link_libraries(log utilities)
