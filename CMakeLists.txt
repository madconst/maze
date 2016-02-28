cmake_minimum_required(VERSION 3.2)

add_definitions("-std=c++11")

add_executable (generate_text_maze 
	generate_text_maze.cpp 
	maze.cpp 
	text_view.cpp
)

add_executable (generate_svg_maze 
	generate_svg_maze.cpp 
	maze.cpp 
	svg_view.cpp
	svg.cpp
)
