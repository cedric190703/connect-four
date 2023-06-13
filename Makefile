# Compiler
CC = gcc
# Compiler flags
CFLAGS = -fsanitize=address -g -lm
# Executable name
EXEC = connect-four

# Source files
SOURCES = main.cpp AI/AI.cpp Game/Board.cpp Game/Game.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

# Linking object files to create the executable
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -lstdc++ -o $@

# Compiling source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean command to remove object files and executable
clean:
	rm -f $(EXEC) $(OBJECTS)
