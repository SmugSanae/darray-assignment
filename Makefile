CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c23

TARGET = lib/darray.a

.PHONY: release
release: CFLAGS += -O3
release: $(TARGET) test

debug: CFLAGS += -O0 -g
debug: $(TARGET) test

.PHONY: all
all:
	mkdir -p lib/darray.a
	mkdir -p bin/darray_test
	mkdir -p all

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf lib bin all


$(TARGET): all all/darray.o
	ar rcs $(TARGET) all/darray.o


.PHONY: tests
tests: LDLIBS += -lcheck -lsubunit
tests: test/darray_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) test/darray_test.c $(TARGET) -o bin/tests/darray_test


all/darray.o: src/darray.c include/darray.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -c src/darray.c -o all/darray.o
