CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c deposito.c produtos.c estrutura.c
OBJS = $(SRCS:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
