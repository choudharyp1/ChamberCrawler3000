CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=main.o game.o floor.o \
	cell.o floortile.o wall.o nswall.o ewwall.o emptytile.o stairway.o passage.o doorway.o chamber.o \
	item.o gold.o small.o normal.o merchanthoard.o dragonhoard.o \
	potion.o atkmod.o defmod.o hpmod.o direction.o \
	character.o player.o shade.o drow.o goblin.o vampire.o troll.o \
	enemy.o givesgold.o dropsgold.o dwarf.o orc.o elf.o halfling.o human.o merchant.o dragon.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o main
.PHONY: clean
