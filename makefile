vpath %.c src
vpath %.h include


feiqiu: feiqiu_run.o feiqiu.o -lpcap
	gcc $^ -o $@

feiqiu_run.o: feiqiu_run.c feiqiu.h feiqiu_types.h
	gcc -c $<

feqiu.o: feiqiu.c feiqiu_types.h
	gcc -c $<

test: feiqiu_test.c
	gcc $< 
