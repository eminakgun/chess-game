CC     = g++
INCDIR = include
CFLAGS = -std=c++11

SRCDIR = src
TESTDIR = test

BINDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRCS))

TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp, $(BINDIR)/%.o, $(TEST_SRCS))

print:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(TEST_SRCS)
	@echo $(TEST_OBJS)

chess: clean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o chess

test: chess $(TEST_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) -o chess


all: chess
	./chess

# $(TESTDIR)/%.cpp
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf chess $(BINDIR)/*.o