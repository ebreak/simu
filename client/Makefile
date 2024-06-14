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
	g++ -o client.$(suffix) *.cc \
		../core/*.cc \
		../core/object/*.cc \
		-I../core \
		-I../tool/include \
		-L../tool/$(OS) \
		-lpyrite -lmocutils -lglfw3 -lopengl32 -lgdi32 -D$(OS) $(ws2_32)

run: build
	./client.$(suffix)

clean:
	$(rm) *.$(suffix)