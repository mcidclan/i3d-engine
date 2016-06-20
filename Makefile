CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe

LIBSRC = $(wildcard *.cpp)
APPSRC = $(wildcard ./scripts/*.cxx)

LIBOBJS = $(notdir $(patsubst %.cpp, %.o, $(LIBSRC)))
APPOBJS = $(notdir $(patsubst %.cxx, %.o, $(APPSRC)))

OBJS := $(addprefix $(BIN), $(APPOBJS)) $(addprefix $(BIN), $(LIBOBJS))

CFLAGS = -W -Wall -ansi -pedantic -O0 -g2 -static -std=gnu++0x -m32 \
		-DGLEW_STATIC -DGLEW_NO_GLU -DGLEW_BUILD -DFREEGLUT_STATIC \
		-I/mingw/include/freetype2 -I./headers -I./scripts \
		-I./scripts/headers

LDFLAGS = -lftgl -lfreetype -lfreeglut_static -lwinmm \
			-lgdi32 -lglew32 -lglu32 -lopengl32

all: $(BIN)$(EXEC)

$(BIN)$(EXEC): $(OBJS) $(DATA)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

$(BIN)%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(BIN)%.o: ./scripts/%.cxx
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(BIN)$(EXEC)
