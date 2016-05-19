CC = g++
CFLAGS = -Wall -std=c++11
SDL_INCLUDE = /usr/local/include/SDL2
INCLUDE = include

BINDIR := bin/default
OBJDIR := obj/default
OBJDIRSRC := obj/default/src

OBJS := $(addprefix $(OBJDIR)/,game.o game_cleanup.o game_loadcontent.o game_onevent.o game_oninit.o game_onloop.o game_onrender.o) $(addprefix $(OBJDIRSRC)/,Bomb.o BombManager.o Destroyer.o DestructibleWall.o Display.o DisplayElement.o DisplayManager.o Enemy.o EnemyManager.o ExitDisplay.o Explosion.o ExplosionManager.o GameDisplay.o KeyboardInput.o Map.o MapObject.o Player.o PlayerManager.o Relay.o SystemTimer.o Timer.o WallDestroyer.o WelcomeDisplay.o)

all: $(OBJS) Bomberman.exe

debug: CFLAGS += -g
#debug: BINDIR := bin/Debug
#debug: OBJDIR := obj/Debug
#debug: OBJDIRSRC := obj/Debug/src
debug: all

release: CFLAGS += -O2
#release: BINDIR := bin/Release
#release: OBJDIR := obj/Release
#release: OBJDIRSRC := obj/Release/src
release: all

$(OBJDIR)/%.o	: %.cpp
	$(CC) $(CFLAGS) -c -I $(SDL_INCLUDE) -I $(INCLUDE) -o $@ $< 

Bomberman.exe : $(OBJS)
	$(CC) $(CFLAGS) -L /usr/local/lib -o $(BINDIR)/Bomberman.exe $(OBJS) -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer 

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR) $(OBJDIRSRC) $(BINDIR) -p

.PHONY: clean all

clean:
	rm -rf *~ obj/ bin/




		