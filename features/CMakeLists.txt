set(SUBSYS_NAME features)
set(SUBSYS_DESC "Object recognition features library")
set(SUBSYS_DEPS common)

set(build TRUE)
CORE_SUBSYS_OPTION(build ${SUBSYS_NAME} ${SUBSYS_DESC} ON)
CORE_SUBSYS_DEPEND(build ${SUBSYS_NAME} DEPS ${SUBSYS_DEPS})

CORE_ADD_DOC(${SUBSYS_NAME})

if(build)
  set(srcs
      src/normals.cpp
      src/curvatures.cpp
      src/sobel.cpp)

  set(incs
      include/core/${SUBSYS_NAME}/normals.h
      include/core/${SUBSYS_NAME}/curvatures.h
      include/core/${SUBSYS_NAME}/sobel.h)

  set(LIB_NAME core_${SUBSYS_NAME})
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include 
                      ${PCL_INCLUDE_DIRS}
                      ${OpenCV_INCLUDE_DIRS})

  CORE_ADD_LIBRARY(${LIB_NAME} ${SUBSYS_NAME} ${srcs} ${incs})
  target_link_libraries(${LIB_NAME} 
                        core_common 
                        ${PCL_LIBRARIES}
                        ${OpenCV_LIBS}) 
  CORE_MAKE_PKGCONFIG(${LIB_NAME} ${SUBSYS_NAME} "${SUBSYS_DESC}" "${SUBSYS_DEPS}" "" "" "" "")

  # Install include files
  CORE_ADD_INCLUDES(${SUBSYS_NAME} ${SUBSYS_NAME} ${incs})

  if(BUILD_TESTS)
    add_subdirectory(test)
  endif(BUILD_TESTS)

endif(build)
