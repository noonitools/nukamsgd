cmake_minimum_required(VERSION 3.22)

project(
  nukamsgd
  VERSION 0.1.0
  DESCRIPTION "Messenger server for C++"
  HOMEPAGE_URL https://github.com/panda5176/biocpp
  LANGUAGES CXX
)


add_subdirectory(src)

set(LIBRARIES io)

foreach(LIBRARY ${LIBRARIES})
  set(LIB_OBJS ${LIB_OBJS} $<TARGET_OBJECTS:${LIBRARY}>)
endforeach()

add_executable(${PROJECT_NAME} nukamsgd.cpp ${LIB_OBJS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
