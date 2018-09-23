YFLAGS = -d                           # force creation of y.tab.h
OBJS = hoc.o init.o math.o symbol.o   # abbrievation

hoc3: $(OBJS)
	gcc -g $(OBJS) -lm -o hoc3

y.tab.h: hoc.o

hoc.o: hoc.h

init.o symbol.o: hoc.h y.tab.h

clean:
	rm -r $(OBJS) y.tab.h hoc.c
