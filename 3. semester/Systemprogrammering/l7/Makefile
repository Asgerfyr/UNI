CXX = g++


SRCS = $(wildcard *.cpp)

TARGETS = $(SRCS:.cpp=.exe)

.PHONY: all run clean

all: $(TARGETS)

%.exe: %.cpp
	$(CXX) -o $@ $<


run-%: %.exe
	./$<

run: $(TARGETS)
	for %%f in ($(TARGETS)) do @echo "Running %%f" & .\%%f


clean:
	del /Q $(wildcard *.exe)
