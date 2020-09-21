CC := gcc
CFLAGS := -Wall -g
target := proc_fan
source := proc_fan.c

$(target): $(source)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(target)
