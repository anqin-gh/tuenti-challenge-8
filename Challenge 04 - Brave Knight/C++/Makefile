SOURCES := $(wildcard *.cc)
OBJECTS := $(subst .cc,.o,$(SOURCES))

main: $(OBJECTS)
	g++ -std=c++11 -o $@ $^

%.o: %.cc
	g++ -std=c++11  -o $@ -c $^ -I.

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

clean:
	rm -f *.o