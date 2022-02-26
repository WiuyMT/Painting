EXEFILE = MyDuckApplication
CXXFLAGS = -c -Wall

$(EXEFILE): Duck.o MallardDuck.o DecoyDuck.o RubberDuck.o QuackBehavior.o MuteQuack.o Quack.o Squeak.o main.o
	g++ $^ -o $@

%.o: %.cpp
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)
.PHONY: clean
