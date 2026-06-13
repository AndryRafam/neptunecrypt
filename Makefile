# To Install: sudo make install
# To Uninstall: sudo make uninstall

ccsrc = $(wildcard src/simpleCipher/*.cpp) \
		$(wildcard src/password/*.cpp) \
		$(wildcard src/driverProgram/*.cpp)
		
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -MMD -MP

obj = $(ccsrc:.cpp=.o)
deps = $(obj:.o=.d)

LDFLAGS = -lcryptopp

poseidon: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


# install
install: poseidon
	mkdir -p /usr/local/bin
		cp -f poseidon /usr/local/bin/poseidon
		
# uninstall
uninstall: poseidon
	rm -f /usr/local/bin/poseidon

-include $(deps)

.PHONY: clean install uninstall
clean:
	rm -f $(obj) $(deps) poseidon


