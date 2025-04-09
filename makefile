# Makefile for compiling and linking C++ project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./Headers
LDFLAGS = -static-libgcc -static-libstdc++ -lmingw32 -Wpedantic -Wmaybe-uninitialized -DSDL2_STATIC -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
BIN_DIR = ./Bin
SRC_DIR = ./Source
OBJ_DIR = ./Obj
RES_DIR = ./Resources

# Find source files and corresponding object files
SOURCES := $(wildcard $(SRC_DIR)/**/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Include directories
INCLUDES := $(shell find ./Headers -type d -exec echo -I{} \;)

# Default target: Build everything
all: $(BIN_DIR)/run.exe

# Create object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile each source file to object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES) 

# Link object files into the final executable
$(BIN_DIR)/run.exe: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Copy resources
copy_resources:
	@xcopy "$(RES_DIR)" "$(BIN_DIR)/Resources" /E /I /K /Y

# Clean up object files and executable
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)/run.exe

# Run the application
run: $(BIN_DIR)/run.exe copy_resources
	@echo Compilation succeeded. Running the app...
	@$(BIN_DIR)/run.exe

.PHONY: all clean run copy_resources
