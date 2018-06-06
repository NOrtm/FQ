vpath %.c src
vpath %.h include

feiqiu_run: feiqiu_run.c
	gcc $< -o $@ -lpcap


test: feiqiu_test.c
	gcc $< 
