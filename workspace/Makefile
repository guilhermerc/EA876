# Macros para compilacao
CC = gcc
CFLAGS = -Wextra -lfl
DIR = src
FILENAME = $(DIR)/main.c
YYTABH = $(DIR)/y.tab.h
YYTABC = $(DIR)/y.tab.c
LEXOUT = $(DIR)/lex.yy.c
YACCFILE = $(DIR)/main.y
LEXFILE = $(DIR)/main.l
PILHA_BIB_C = $(DIR)/pilha_bib.c
PILHA_BIB_H = $(DIR)/pilha_bib.h
PILHA_BIB_O = $(DIR)/pilha_bib.o
TARGET = ./main
BJS = $(SRCS:.c=.o)
YACC = bison
LEX = flex


# Macros para teste
BASH = sh
TEST_SCRIPT = test.sh
VERBOSE ?= 1

# Macros para construcao do zip
ZIP = zip
USERNAME ?= $(USER)
ZIPFILE = $(USERNAME).zip
EXTENSIONS = *.c *.h *.in *.out *.sh

.PHONY: depend clean

all:$(TARGET)

$(TARGET): $(PILHA_BIB_O) $(LEXOUT) $(YYTABC)
	$(CC) -o$(TARGET) $(LEXOUT) $(YYTABC) $(PILHA_BIB_O) $(CFLAGS)

$(PILHA_BIB_O): $(PILHA_BIB_C) $(PILHA_BIB_H)
	$(CC) -c $(PILHA_BIB_C)

$(LEXOUT):$(LEXFILE) $(YYTABC)
	$(LEX) -o$(LEXOUT) $(LEXFILE)

$(YYTABC):$(YACCFILE)
	$(YACC) -o$(YYTABC) -dy $(YACCFILE)

test:all
	$(BASH) $(TEST_SCRIPT) $(TARGET) $(VERBOSE)

zip:clean
	$(ZIP) -R $(ZIPFILE)  Makefile $(EXTENSIONS)

clean:
	$(RM) $(YYTABC)
	$(RM) $(YYTABH)
	$(RM) $(LEXOUT)
	$(RM) ./$(TARGET)
	$(RM) $(DIR)/*.o
	$(RM) ./$(ZIPFILE)
