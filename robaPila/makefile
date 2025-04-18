raylibInc = -I ../lib/raylib/src
raylibLib = -L ../lib/raylib/src -l raylib

raylibDep = -framework IOKit -framework Cocoa -framework OpenGL

boostInc = -I /Users/fernandosanchez/development/third-libs/boost_1_87_0

robaPila: Cards.o Dealer.o Player.o robaPila.o 
	@g++ -std=c++20 -mmacosx-version-min=10.14 src/obj/Cards.o src/obj/Dealer.o src/obj/Player.o src/obj/robaPila.o ${raylibLib} ${raylibDep} -o robaPila
	@mv robaPila execs 
	@echo "built robaPila!"

playground: src/playground.cpp
	@g++ -std=c++20 -mmacosx-version-min=10.14 src/playground.cpp ${raylibInc} ${raylibDep} ${raylibLib} -o playground
	@mv playground execs
	@echo "built playground"

robaPila.o: src/main.cpp
	@g++ -std=c++20 -mmacosx-version-min=10.14 ${raylibInc} ${boostInc} -I. src/main.cpp -c -o robaPila.o
	@mv robaPila.o src/obj

Cards.o: src/Cards.cpp
	@g++ -std=c++20 -mmacosx-version-min=10.14 ${raylibInc} ${boostInc} -I. src/Cards.cpp -c -o Cards.o
	@mv Cards.o src/obj

Dealer.o: src/Dealer.cpp
	@g++ -std=c++20 -mmacosx-version-min=10.14 ${raylibInc} ${boostInc} -I. src/Dealer.cpp -c -o Dealer.o
	@mv Dealer.o src/obj

Player.o: src/Player.cpp
	@g++ -std=c++20 -mmacosx-version-min=10.14 ${raylibInc} ${boostInc} -I. src/Player.cpp -c -o Player.o
	@mv Player.o src/obj