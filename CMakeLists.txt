cmake_minimum_required( VERSION 3.4.0 )

project( shared_lib CXX )			

set( SOURCE_LIB SMP.cpp PWF.cpp PHYP.cpp Pendulum.cpp Pendulum.h )		

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library( Pendulum SHARED ${SOURCE_LIB} )
