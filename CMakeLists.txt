project(ape)
cmake_minimum_required(VERSION 2.8)

add_definitions(-O2 -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Wcast-qual -Woverloaded-virtual -pedantic -Wno-old-style-cast -Wno-unused-result -Wno-cast-qual -Wno-sign-compare -fdiagnostics-show-option)

add_library(${PROJECT_NAME}-lib SHARED src/lib/sys.cpp src/lib/loc.cpp src/lib/str.cpp src/lib/compile.cpp src/lib/convert.cpp src/lib/libgen.cpp src/lib/unistd.cpp)
set_target_properties(${PROJECT_NAME}-lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME}-lib DESTINATION lib)
install(DIRECTORY src/lib/ DESTINATION include/ape FILES_MATCHING PATTERN "*.h*")

file(MAKE_DIRECTORY bin)

add_executable(${PROJECT_NAME}-bin src/${PROJECT_NAME}.cpp)
set_target_properties(${PROJECT_NAME}-bin PROPERTIES OUTPUT_NAME bin/${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}-bin ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-bin DESTINATION bin)

add_executable(${PROJECT_NAME}-make src/${PROJECT_NAME}-make.cpp)
set_target_properties(${PROJECT_NAME}-make PROPERTIES OUTPUT_NAME bin/${PROJECT_NAME}-make)
target_link_libraries(${PROJECT_NAME}-make ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-make DESTINATION bin)

add_executable(${PROJECT_NAME}-compile src/${PROJECT_NAME}-compile.cpp)
set_target_properties(${PROJECT_NAME}-compile PROPERTIES OUTPUT_NAME bin/${PROJECT_NAME}-compile)
target_link_libraries(${PROJECT_NAME}-compile ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-compile DESTINATION bin)

include(cmake/packaging.cmake)

