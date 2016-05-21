CC = g++
CFLAGS = -Wall -std=c++11

SDL_INCLUDE = /usr/local/include/SDL2
SDL_LIB = /usr/local/lib
SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

INCLUDE = include

DIR_BIN := bin/default
DIR_OBJ := obj/default
DIR_OBJ_SRC := obj/default/src

OBJ_BASE := \
game.o \
game_cleanup.o \
game_loadcontent.o \
game_onevent.o \
game_oninit.o \
game_onloop.o \
game_onrender.o

OBJ_BASE_SRC := \
Bomb.o \
BombManager.o \
Destroyer.o \
DestructibleWall.o \
Display.o \
DisplayElement.o \
DisplayManager.o \
Enemy.o \
EnemyManager.o \
ExitDisplay.o \
Explosion.o \
ExplosionManager.o \
GameDisplay.o \
KeyboardInput.o \
Map.o \
MapObject.o \
Player.o \
PlayerManager.o \
Relay.o \
SystemTimer.o \
Timer.o \
WallDestroyer.o \
WelcomeDisplay.o

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
	mkdir $(DIR_OBJ) $(DIR_OBJ_SRC) $(DIR_BIN) -p

.PHONY: clean all

clean:
	rm -rf *~ obj/ bin/




		