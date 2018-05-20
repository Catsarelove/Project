cmake_minimum_required( VERSION 3.4.0 )

project( shared_lib CXX )			

set( SOURCE_LIB sources/SMP.cpp sources/PWF.cpp sources/PHYP.cpp sources/Pendulum.cpp headers/Pendulum.h )		

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library( Pendulum SHARED ${SOURCE_LIB} )
