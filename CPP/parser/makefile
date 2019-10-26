CC = g++
CFLAGS = -ansi -pedantic

INCLUDES = 
LIBS =-lm

SRCS = mainTest.cpp parser_t.cpp analyzer_t.cpp

OBJS = $(SRCS:.c=.o)

MAIN = mainOut

all: $(MAIN)
	@echo Program named ‘Exe’ has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM)*.o*~$(MAIN)

