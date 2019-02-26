CFLAGS = -lpthread -Wall
sem_w: POSIXSem_w.cpp
	gcc $^ ${CFLAGS} -o $@
sem_r: POSIXSem_r.cpp
	gcc $^ ${CFLAGS} -o $@
clean:
	rm *.o
