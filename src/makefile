################################################################################
# Project Settings
################################################################################

# Name of the target (files will be named like that)
PROJECT=dstack

OBJECTS  = main.o
OBJECTS += cmd.o
OBJECTS += stack.o

################################################################################
# Compiler Settings
################################################################################
CFLAGS += -g
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -std=gnu99
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields

COMPILE = gcc $(CFLAGS) 

################################################################################
# Linker Settings
################################################################################

LDFLAGS = 

LINK = gcc $(LDFLAGS)



################################################################################
# Main rules
################################################################################

all: clean build

build: $(OBJECTS) link

link:
	$(LINK) -o $(PROJECT) $(OBJECTS)

clean:
	rm -rf $(PROJECT)
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.hex


################################################################################
# Generic rule for compiling C files:
################################################################################
.c.o:
	$(COMPILE) -c $< -o $@


################################################################################
# Generic rule for assembling Assembler source files:
################################################################################
.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@


################################################################################
# Generic rule for compiling C to assembler, used for debugging only.
################################################################################
.c.s:
	$(COMPILE) -S $< -o $@

