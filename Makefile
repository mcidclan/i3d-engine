CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe

SRCFILES = $(wildcard *.cpp)
OBJS = $(notdir $(patsubst %.cpp, %.o, $(SRCFILES)))
OBJS := $(addprefix $(BIN), $(OBJS))

CFLAGS = -W -Wall -ansi -pedantic -O0 -g2 -static \
		-DGLEW_STATIC -DGLEW_NO_GLU -DGLEW_BUILD -DFREEGLUT_STATIC \
		-I/mingw/include/freetype2 -I./headers -I./scripts

LDFLAGS = -lftgl -lfreetype -lfreeglut_static -lwinmm \
			-lgdi32 -lglew32 -lglu32 -lopengl32

all: $(BIN)$(EXEC)

$(BIN)$(EXEC): $(OBJS) $(DATA)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

$(BIN)%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(BIN)$(EXEC)
