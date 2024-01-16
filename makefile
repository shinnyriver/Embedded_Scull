CC := gcc
CFLAGS := -std=c99 -Wall -Wextra

SRCS := main.c fops.c
OBJS := $(SRCS:.c=.o)

TARGET := my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
 
