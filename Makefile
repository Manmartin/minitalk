CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SSRC = server.c aux.c
CSRC = client.c aux.c

SOBJ = $(SSRC:.c=.o)
COBJ = $(CSRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER):	$(SOBJ)
	$(CC) $(CFLAGS) $(SSRC) -o $(SERVER)
 
$(CLIENT): $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(SOBJ) $(COBJ)
fclean: clean
	rm -f $(SERVER) $(CLIENT)
re: fclean all

.PHONY: all clean fclean re
