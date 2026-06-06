ccsrc = $(wildcard xchacha20file/* .hpp) \
		$(wildcard xchacha20file/* .cpp) \
		$(wildcard password/* .hpp) \
		$(wildcard password/* .cpp) \
		$(wildcard driverProgram/* .cpp)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23

obj = $(ccsrc: .cpp=.o)
deps = $(obj: .o=.d)

LDFLAGS = -lcryptopp

neptune: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
