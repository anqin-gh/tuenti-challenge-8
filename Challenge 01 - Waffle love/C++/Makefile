SOURCES := $(wildcard *.cc)
OBJECTS := $(subst .cc,.o,$(SOURCES))

main.out: $(OBJECTS)
	g++ -o $@ $^

%.o: %.cc
	g++ -o $@ -c $^ -I.

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

clean:
	rm -f *.o