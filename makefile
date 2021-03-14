
GPP=g++


run: demo
	./$^

demo: main.o Editor.o Document.o
	$(GPP) $^ -o demo

%.o: %.cpp 
	$(GPP) --compile $< -o $@

clean:
	rm -f *.o demo test