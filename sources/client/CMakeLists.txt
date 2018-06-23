cmake_minimum_required( VERSION 3.9 )
project( zappy )

set(MY_MAKE_CXX_FLAGS "-Wall -Werror -Wextra -pedantic -Wfloat-equal -Wshadow \
 -Wstrict-overflow=5 -Wcast-align -Wconversion -ftrapv \
-Wuninitialized -Wuseless-cast -Wold-style-cast -Wnon-virtual-dtor")

include_directories(../../includes/client ServerCommunication Parsing AI)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)

if (CMAKE_CXX_CPPCHECK)
	list( APPEND CMAKE_CXX_CPPCHECK
		  "--enable=warning,performance,style")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../..")

set( CMAKE_CXX_STANDARD 17 )


set_source_files_properties(
		AI/IGraph.cpp
		AI/IGraph.hpp
		AI/ZappyGraph.cpp
		AI/ZappyGraph.hpp
		AI/linux_color.hpp
		AI/PathFinder2D.cpp
		AI/PathFinder2D.hpp
		AI/ZappyAi.cpp
		AI/ZappyAi.hpp
		AI/DecisionTree.cpp
		AI/DecisionTree.hpp
		PROPERTIES
		COMPILE_FLAGS ${MY_MAKE_CXX_FLAGS}
)

add_executable( zappy_ai
				main.cpp
				ServerCommunication/CommunicateToServer.cpp
				ServerCommunication/CommunicateToServer.hpp
				ServerCommunication/Client.cpp
				ServerCommunication/Client.hpp
				Parsing/ParseArgs.cpp
				Parsing/ParseArgs.hpp
				AI/IGraph.cpp
				AI/IGraph.hpp
				AI/ZappyGraph.cpp
				AI/ZappyGraph.hpp
				AI/linux_color.hpp
				AI/PathFinder2D.cpp
				AI/PathFinder2D.hpp
				AI/ZappyAi.cpp
				AI/ZappyAi.hpp
				AI/DecisionTree.cpp
				AI/DecisionTree.hpp )