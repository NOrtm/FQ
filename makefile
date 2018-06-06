vpath %.c src test
vpath %.h include

objects = feiqiu_run.o feiqiu.o

feiqiu: $(objects) -lpcap
	gcc $^ -o $@

feiqiu_run.o: feiqiu.h feiqiu_types.h

feqiu.o: feiqiu_types.h

.PHONY: test
test: feiqiu_test.c feiqiu.c	
	g++ $^ -o unit_test -lpthread -lgtest -lpcap
	./unit_test

.PHONY: clean
clean:
	rm feiqiu $(objects)

.PHONY: clean_test
clean_test:
	rm unit_test
