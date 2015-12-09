OBJECTS = main.o parsetree.o
HEADERS = parsetree.h
Program4: $(OBJECTS)
	g++ $^ -o Lab12
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o lab12
