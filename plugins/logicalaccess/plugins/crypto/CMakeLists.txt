
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
else()
  if (MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
  endif ()
endif()

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE HDPPRS *.hpp)

set(INCLUDE ${HDRS} ${HDPPRS} )

add_library(
	logicalaccess-cryptolib
	STATIC
	${SRCS}
	${INCLUDE}
  )
  
 
install ( FILES ${INCLUDE} DESTINATION ${LIBLOGICALACCESS_INCLUDE_DIR}/logicalaccess/plugins/crypto )
install ( TARGETS logicalaccess-cryptolib ARCHIVE DESTINATION lib/${LIB_SUFFIX} LIBRARY DESTINATION lib/${LIB_SUFFIX} )
