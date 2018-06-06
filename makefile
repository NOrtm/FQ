vpath %.c src test
vpath %.h include

objects = feiqiu_run.o feiqiu.o

feiqiu: $(objects) -lpcap
	gcc $^ -o $@

feiqiu_run.o: feiqiu.h feiqiu_types.h

feqiu.o: feiqiu_types.h

test: feiqiu_test.c feiqiu.c	
	g++ $^ -o $@ -lpthread -lgtest
	./test

.PHONY: clean
clean:
	rm feiqiu $(objects)
