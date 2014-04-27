set (SOURCES
	main.cpp
)

set (HEADERS
	MyWindow.h
	MyScene.h
	GraphicsView.h
)

qt4_wrap_cpp (SOURCES ${HEADERS})
add_executable (fifteen ${SOURCES})
target_link_libraries (fifteen ${QT_LIBRARIES})
