cmake_minimum_required(VERSION 3.22)

project(apriltag1 VERSION 0.1.0 LANGUAGES CXX C)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

################################################################################
# Target setup
################################################################################
file(GLOB SOURCE_FILES "src/*.cc")
file(GLOB HEADER_FILES "include/apriltag1/*.h")

add_library(apriltag1 ${SOURCE_FILES})

target_include_directories(apriltag1 SYSTEM PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(apriltag1 PUBLIC ${OpenCV_LIBS} Eigen3::Eigen)
set_property(TARGET apriltag1 PROPERTY POSITION_INDEPENDENT_CODE ON)

################################################################################
# Install
################################################################################

set(apriltag1_INCLUDE_DIRS ${CMAKE_INSTALL_INCLUDEDIR})
set(apriltag1_LIBRARIES apriltag1)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/apriltag1ConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

configure_package_config_file(cmake/apriltag1Config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/apriltag1Config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/apriltag1/cmake
	PATH_VARS
		apriltag1_INCLUDE_DIRS
		apriltag1_LIBRARIES
)

install(TARGETS apriltag1
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/apriltag1
	COMPONENT library
)

install(FILES
	${HEADER_FILES}
	DESTINATION
		${CMAKE_INSTALL_INCLUDEDIR}/apriltag1
	COMPONENT header
)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/apriltag1Config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/apriltag1ConfigVersion.cmake
	DESTINATION
		${CMAKE_INSTALL_LIBDIR}/apriltag1/cmake
	COMPONENT package
)


