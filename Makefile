CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe

SRCFILES = $(wildcard *.cpp)
OBJS = $(notdir $(patsubst %.cpp, %.o, $(SRCFILES)))
#OBJS = main.o
OBJS := $(addprefix $(BIN), $(OBJS))

CFLAGS = -W -Wall -ansi -pedantic -O0 -g2 \
		 -static
#-mwindows
#-Wpadded -Wpacked
LDFLAGS = ./glut32.lib -lglew32.dll  -lopengl32 -lglu32
#-lglut32

#
#-static-libgcc -static-libstdc++ -mwindows -enable-auto-import
# -lstdc++

all: $(BIN)$(EXEC)

$(BIN)$(EXEC): $(OBJS) $(DATA)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

$(BIN)%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(BIN)$(EXEC)
