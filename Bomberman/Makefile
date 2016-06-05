CC = g++
CFLAGS = -Wall -std=c++11

SDL_INCLUDE = /usr/local/include/SDL2
SDL_LIB = /usr/local/lib
SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

INCLUDE = include

DIR_BIN := bin
DIR_OBJ := obj
DIR_OBJ_SRC := obj/src

DIR_OBJ_SRC_OTHER := \
obj/src/Destroyer \
obj/src/Display \
obj/src/Entity \
obj/src/Manager \
obj/src/System \
obj/src/Utility \

OBJ_BASE := \
game.o \
game_cleanup.o \
game_loadcontent.o \
game_onevent.o \
game_oninit.o \
game_onloop.o \
game_onrender.o

OBJ_BASE_SRC := \
Destroyer/Destroyer.o \
Destroyer/WallDestroyer.o \
Display/Display.o \
Display/DisplayElement.o \
Display/DisplayManager.o \
Display/ExitDisplay.o \
Display/GameDisplay.o \
Display/LoadingDisplay.o \
Display/MainMenuDisplay.o \
Display/PauseDisplay.o \
Display/WelcomeDisplay.o \
Entity/Bomb.o \
Entity/DestructibleWall.o \
Entity/Enemy.o \
Entity/EnemyOne.o \
Entity/EnemyThree.o \
Entity/EnemyTwo.o \
Entity/Explosion.o \
Entity/MapObject.o \
Entity/PickUp.o \
Entity/Player.o \
Manager/BombManager.o \
Manager/EnemyManager.o \
Manager/ExplosionManager.o \
Manager/PlayerManager.o \
Manager/PickUpManager.o \
Manager/Map.o \
System/FreeTimer.o \
System/KeyboardInput.o \
System/SystemTimer.o \
System/TextRenderer.o \
Utility/Relay.o \
Utility/Timer.o

OBJS := $(addprefix $(DIR_OBJ)/,$(OBJ_BASE)) $(addprefix $(DIR_OBJ_SRC)/,$(OBJ_BASE_SRC))

all: $(OBJS) Bomberman.exe

debug: CFLAGS += -g
#debug: DIR_BIN := bin/debug
#debug: DIR_OBJ := obj/debug
#debug: DIR_OBJ_SRC := obj/debug/src
#debug: OBJS := $(addprefix $(DIR_OBJ)/,$(OBJ_BASE)) $(addprefix $(DIR_OBJ_SRC)/,$(OBJ_BASE_SRC))
debug: all

release: CFLAGS += -O2
#release: DIR_BIN := bin/release
#release: DIR_OBJ := obj/release
#release: DIR_OBJ_SRC := obj/release/src:
#release: OBJS := $(addprefix $(DIR_OBJ)/,$(OBJ_BASE)) $(addprefix $(DIR_OBJ_SRC)/,$(OBJ_BASE_SRC))
release: all

$(DIR_OBJ)/%.o	: %.cpp
	$(CC) $(CFLAGS) -c -I $(SDL_INCLUDE) -I $(INCLUDE) -o $@ $<

Bomberman.exe : $(OBJS)
	$(CC) $(CFLAGS) -L $(SDL_LIB) -o $(DIR_BIN)/Bomberman.exe $(OBJS) $(SDL_FLAGS)

$(OBJS): | $(DIR_OBJ)

$(DIR_OBJ):
	mkdir $(DIR_OBJ) $(DIR_OBJ_SRC) $(DIR_OBJ_SRC_OTHER) $(DIR_BIN) -p

.PHONY: clean all

clean:
	rm -rf *~ obj/ bin/
