CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe

SRCFILES = $(wildcard *.cpp)
OBJS = $(notdir $(patsubst %.cpp, %.o, $(SRCFILES)))
OBJS := $(addprefix $(BIN), $(OBJS))

CFLAGS = -W -Wall -Wpadded -Wpacked -ansi -pedantic -O0 -g2 \
		 -static -mwindows

LDFLAGS = -lglew32 -lglut32 -lopengl32 -lglu32

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
