project( AudioVisualProject )

cmake_minimum_required( VERSION 2.8 )
add_definitions( -Wall -Winline)
set ( CMAKE_CXX_STANDARD 14 )

file(GLOB_RECURSE FILE_CPP src/*.cpp)
file(GLOB_RECURSE FILE_H src/*.h)

add_executable( ${PROJECT_NAME} ${FILE_CPP} ${FILE_H} )

# OpenAL
set( OPENAL_LIBRARY      /usr/lib/x86_64-linux-gnu/libopenal.so )
set( ALUT_LIBRARY        /usr/lib/x86_64-linux-gnu/libalut.so )
set( OPENAL_INCLUDE      /usr/include )
include_directories( ${OPENAL_INCLUDE} )
target_link_libraries( ${PROJECT_NAME} ${OPENAL_LIBRARY} ${ALUT_LIBRARY})
