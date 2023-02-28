SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)

ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)gcc
endif

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	-rm -f *.o $(TARGET)
