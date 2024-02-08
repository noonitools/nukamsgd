project(io)

file(GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} OBJECT ${SOURCES}
        listener.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)