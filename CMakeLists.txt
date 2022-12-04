cmake_minimum_required (VERSION 3.8)

project (hyp_par)

find_package(OpenCASCADE)

include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})

add_executable(hyp_par
main.cpp
main.h
Viewer.cpp
Viewer.h
ViewerInteractor.cpp
ViewerInteractor.h
HyperbolicParaboloid.h
HyperbolicParaboloid.cpp
)

foreach(LIB ${OpenCASCADE_LIBRARIES})
	target_link_libraries(hyp_par debug     ${OpenCASCADE_LIBRARY_DIR}d/${LIB}.lib)
 	target_link_libraries(hyp_par optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()

set_property(TARGET hyp_par PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=$<$<CONFIG:DEBUG>:${OpenCASCADE_BINARY_DIR}d>$<$<NOT:$<CONFIG:DEBUG>>:${OpenCASCADE_BINARY_DIR}>;%PATH%")