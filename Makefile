all: main libfoo.so libbar.so

libfoo.so: foo.c
	$(CC) $< -o $@ -Wl,-soname,$@ -shared

libbar.so: bar.c libfoo.so
	$(CC) $< -o $@ -Wl,-soname,$@ -shared -L. -lfoo

main: main.c
	$(CC) $< -o $@

.PHONY: clean
clean:
	rm *.so main
