CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe

SRC = ./

OBJS = $(notdir $(patsubst %.cpp, %.o, $(SRC)))
OBJS := $(addprefix $(BIN), $(OBJS))

CFLAGS = -W -Wall -Wpadded -Wpacked -pedantic -O0 -g2 \
		 -static

LDFLAGS = ./glut32.lib -lopengl32 -lglu32

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
