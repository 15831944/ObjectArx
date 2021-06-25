cmake_minimum_required(VERSION 2.8.8)

set(STATUSBARTEST_ZRX StatusBarTestDemo)

find_package(Qt5 REQUIRED Core)
find_package(Qt5 REQUIRED Widgets)
find_package(Qt5 REQUIRED Xml)

add_definitions(-DINITGUID)

set(${STATUSBARTEST_ZRX}_SRC_inc
	./inc/StdAfx.h
	./inc/ZwmTrayItem.h
)

set(${STATUSBARTEST_ZRX}_SRC_src
	./src/acrxEntryPoint.cpp
	./src/HelloWorld.cpp
	./src/StdAfx.cpp
	./src/ZwmTrayItem.cpp
)

zw_sources(${STATUSBARTEST_ZRX} 
	${${STATUSBARTEST_ZRX}_SRC_inc}
	${${STATUSBARTEST_ZRX}_SRC_src}
)
source_group(inc FILES ${${STATUSBARTEST_ZRX}_SRC_inc})
source_group(src FILES ${${STATUSBARTEST_ZRX}_SRC_src})

include_directories(
	./inc
	${ZW_SDK_DIR}/nowin/ZwMFCWrapper/include
	${Qt5Core_INCLUDE_DIRS}
)

zw_library_zrx(${STATUSBARTEST_ZRX})

target_link_libraries(${STATUSBARTEST_ZRX}
	"-Wl,--whole-archive"
	${ZWZRX_LIB}
	"-Wl,-no-whole-archive"
	ZwRx
	ZWCADE2
	ZwMFCWrapper
	${Qt5Widgets_LIBRARIES}
	${Qt5Core_LIBRARIES}
	${Qt5Xml_LIBRARIES}
)

zw_project_group(${ZWARCTEXT_ZRX} "Services")