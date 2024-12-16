# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Targets
TARGET = calculator
OBJECTS = main.o calculator.o

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build
clean:
	rm -f $(TARGET) $(OBJECTS)



