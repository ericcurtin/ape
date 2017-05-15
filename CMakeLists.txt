project(cscr)
cmake_minimum_required(VERSION 2.8)

add_library(${PROJECT_NAME}-lib SHARED sys.cpp loc.cpp)
set_target_properties(${PROJECT_NAME}-lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME}-lib DESTINATION /usr/lib/)

add_executable(${PROJECT_NAME}-bin ${PROJECT_NAME}.cpp)
set_target_properties(${PROJECT_NAME}-bin PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}-bin ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-bin DESTINATION /usr/bin/)

add_executable(${PROJECT_NAME}-make ${PROJECT_NAME}-make.cpp)
target_link_libraries(${PROJECT_NAME}-make ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-make DESTINATION /usr/bin/)

add_executable(${PROJECT_NAME}-compile ${PROJECT_NAME}-compile.cpp)
target_link_libraries(${PROJECT_NAME}-compile ${PROJECT_NAME}-lib)
install(TARGETS ${PROJECT_NAME}-compile DESTINATION /usr/bin/)

set(CMAKE_BUILD_TYPE Debug)

