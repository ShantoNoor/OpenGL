SRC_DIR         =  src
OBJ_NAME        =  main
COMPILER        =  clang++
INCLUDE_ONE     =  /opt/homebrew/Cellar/glfw/3.3.6/include
LIB_ONE         =  /opt/homebrew/Cellar/glfw/3.3.6/lib
INCLUDE_TWO     =  /opt/homebrew/Cellar/glew/2.2.0_1/include
LIB_TWO         =  /opt/homebrew/Cellar/glew/2.2.0_1/lib
COMPILER_FLAGS  =  -std=c++17 -Wall -O0 -g
LINKER_FLAGS    =  -framework OpenGL -lGLEW -lglfw.3.3

SRC_FILES       =  $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS   =  -I$(INCLUDE_ONE) -I$(INCLUDE_TWO) -I./src
LIB_PATHS       =  -L$(LIB_ONE) -L$(LIB_TWO)

all:
	$(COMPILER) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIB_PATHS) $(SRC_FILES) -o $(OBJ_NAME)
	