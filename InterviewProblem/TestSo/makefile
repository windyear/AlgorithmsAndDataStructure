.PHONY: build test clean

build: libTestSo.so

libTestSo.so: TestSo.o
	gcc -o $@ -shared $^

TestSo.o: TestSo.c
	gcc -c -fPIC $^

test: a.out

a.out: TestSoMain.c libTestSo.so
	gcc TestSoMain.c -L. -lTestSo

clean:
	rm -f *.o *.so a.out
