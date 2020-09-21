CC := gcc
CFLAGS := -Wall -g

main_target := proc_fan
sub_target := testsim
targets := $(main_target) $(sub_target)

main_dependencies := proc_fan.c $(sub_target)
sub_dependencies := testsim.c

$(main_target): $(main_dependencies)
	$(CC) $(CFLAGS) $< -o $@

$(sub_target): $(sub_dependencies)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(targets)
