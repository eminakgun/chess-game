CC     = g++
INCDIR = include
CFLAGS = -std=c++11

SRCDIR = src

BINDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRCS))

print:
	@echo $(SRCS)
	@echo $(OBJS)

chess: clean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o chess

all: chess
	./chess

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf chess $(BINDIR)/*.o