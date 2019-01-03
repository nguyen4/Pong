LIBS = -lsfml-graphics -lsfml-window -lsfml-system

pong: main.o Paddle.o Ball.o UIElement.o
	@echo "***Making Pong..."
	g++ main.o Paddle.o Ball.o UIElement.o -o pong $(LIBS)
	@echo "***Done"

main.o: main.cpp globalVar.h Paddle.hpp Ball.hpp UIElement.hpp
	@echo "***Compiling main.cpp..."
	g++ -std=c++11 -c main.cpp
	@echo "***Done"

Paddle.o: Paddle.cpp globalVar.h
	@echo "***Compiling Paddle.cpp..."
	g++ -std=c++11 -c Paddle.cpp
	@echo "***Done"

Ball.o: Ball.cpp globalVar.h Paddle.hpp
	@echo "***Compiling Ball.cpp..."
	g++ -std=c++11 -c Ball.cpp
	@echo "***Done"

UIElement.o: UIElement.cpp Paddle.hpp
	@echo "***Compiling UIElement.cpp..."
	g++ -std=c++11 -c UIElement.cpp
	@echo "***Done"

clean:
	-rm *.o *.gch