CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include
TARGET   = gestor_streaming
SRCDIR   = src
BINDIR   = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

all: $(BINDIR) $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BINDIR) $(TARGET)

.PHONY: all run clean
