CC = g++
BIN = ./bin/
EXEC = i3d-engine.exe


LIB_PATH = .
LIB_PATH_UI = ./i3d-gui
LIB_PATH_UTIL = ./i3d-utility
#LIB_PATH_CLIENT = ./i3d-client
DEMO_PATH = ./i3d-demo


LIB_SRC = $(wildcard *.cpp)
LIB_SRC_UI = $(wildcard $(LIB_PATH_UI)/*.cpp)
LIB_SRC_UTIL = $(wildcard $(LIB_PATH_UTIL)/*.cpp)
#LIB_SRC_CLIENT = $(wildcard $(LIB_PATH_CLIENT)/*.cpp)
DEMO_SRC = $(wildcard $(DEMO_PATH)/*.cpp)


LIB_OBJS = $(notdir $(patsubst %.cpp, %.o, $(LIB_SRC)))
LIB_OBJS_UI = $(notdir $(patsubst %.cpp, %.o, $(LIB_SRC_UI)))
LIB_OBJS_UTIL = $(notdir $(patsubst %.cpp, %.o, $(LIB_SRC_UTIL)))
#LIB_OBJS_CLIENT = $(notdir $(patsubst %.cpp, %.o, $(LIB_SRC_CLIENT)))
DEMO_OBJS = $(notdir $(patsubst %.cpp, %.o, $(DEMO_SRC)))


OBJS := $(addprefix $(BIN), $(LIB_OBJS)) \
		$(addprefix $(BIN), $(LIB_OBJS_UI)) \
		$(addprefix $(BIN), $(LIB_OBJS_UTIL)) \
		$(addprefix $(BIN), $(DEMO_OBJS))

#$(addprefix $(BIN), $(LIB_OBJS_CLIENT)) \

		
CFLAGS = -W -Wall -ansi -pedantic -O0 -g2 -static -std=gnu++0x -m32 \
		-DGLEW_STATIC -DGLEW_NO_GLU -DGLEW_BUILD -DFREEGLUT_STATIC \
		-I/mingw/include/freetype2 \
		-I$(LIB_PATH)/headers \
		-I$(LIB_PATH_UI)/headers \
		-I$(LIB_PATH_UTIL)/headers \
		-I$(DEMO_PATH)/headers

#-I$(LIB_PATH_CLIENT)/headers \

LDFLAGS = -lftgl -lfreetype -lfreeglut_static -lglew32 \
	-lopengl32 -lglu32 -lgdi32 -lwinmm -lpng -lz

all: $(BIN)$(EXEC)

	
$(BIN)$(EXEC): $(OBJS) $(DATA)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(BIN)%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(BIN)%.o: $(LIB_PATH_UI)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(BIN)%.o: $(LIB_PATH_UTIL)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

#$(BIN)%.o: $(LIB_PATH_CLIENT)/%.cpp
#	$(CC) -o $@ -c $< $(CFLAGS)

$(BIN)%.o: $(DEMO_PATH)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf $(OBJS)
	rm -rf $(BIN)$(EXEC)
