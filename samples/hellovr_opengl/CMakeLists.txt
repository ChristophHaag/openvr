find_package(SDL2 REQUIRED)
add_executable (hellovr hellovr_opengl_main.cpp ../../samples/shared/pathtools.cpp ../../samples/shared/lodepng.cpp ../../samples/shared/Matrices.cpp)

include_directories(${SDL2_INCLUDE_DIR} "${OpenVR_SOURCE_DIR}/headers" "${OpenVR_SOURCE_DIR}/samples")

find_library(OPENVR_LIB openvr_api "${OpenVR_SOURCE_DIR}/lib/linux${ARCH}" NO_DEFAULT_PATH) #TODO other operating systems
MESSAGE ("Found libopenvr_api: ${OPENVR_LIB}")

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

if ("${ARCH}" STREQUAL "32")
        set_target_properties(hellovr PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif()

configure_file(run_hellovr.sh run_hellovr.sh COPYONLY)
configure_file(../bin/cube_texture.png ../cube_texture.png COPYONLY)

#set_property(TARGET hellovr PROPERTY CXX_STANDARD 11) #Requires CMake 3.1
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

target_link_libraries (hellovr LINK_PUBLIC openvr_api ${SDL2_LIBRARY} ${OPENVR_LIB} ${GLEW_LIBRARIES} dl GL)
