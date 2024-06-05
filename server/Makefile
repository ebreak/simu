ifeq ($(OS), Windows_NT)
	OS     = Windows
	rm     = del
	suffix = exe
	ws2_32 = -lws2_32
else
	rm     = rm
	suffix = elf
endif

build: *.cc
	g++ -o server.$(suffix) *.cc \
		-I../core \
		../core/*.cc \
		-IC:\include \
		-LC:\lib \
		-lpyrite -lmocutils -D$(OS) $(ws2_32)

run: build
	./server.$(suffix)

clean:
	$(rm) *.$(suffix)