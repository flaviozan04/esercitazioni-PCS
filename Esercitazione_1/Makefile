CXX = clang++

SRCS = main.cpp read.cpp write.cpp
OBJS := $(SRCS:%.cpp=%.o)

CXXFLAGS += -O3
LDFLAGS +=

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

myprogram: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) myprogram