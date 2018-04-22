# Macros para compilação

COMPILER = gcc
COMPILER_FLAGS = -Wextra -lfl
DIRECTORY = src
FILENAME = $(DIRECTORY)/main.c
YYTAB_H = $(DIRECTORY)/y.tab.h
YYTAB_C = $(DIRECTORY)/y.tab.c
LEXOUT = $(DIRECTORY)/lex.yy.c
YACCFILE = $(DIRECTORY)/main.y
LEXFILE = $(DIRECTORY)/main.l
PILHA_BIB_C = $(DIRECTORY)/pilha_bib.c
PILHA_BIB_H = $(DIRECTORY)/pilha_bib.h
PILHA_BIB_O = $(DIRECTORY)/pilha_bib.o
TARGET = main
BJS = $(SRCS:.c=.o)
BISON = bison
FLEX = flex

# Macros para teste

BASH = sh
TEST_SCRIPT = test.sh

# Macros para construção do zip
ZIP = zip
NOME_PROJETO = trabalho_01
ZIPFILE = $(NOME_PROJETO).zip
EXTENSIONS = *.c *.h *.in *.out *.sh

.PHONY: depend clean

all:$(TARGET)

$(TARGET): $(PILHA_BIB_O) $(LEXOUT) $(YYTAB_C)
	$(COMPILER) -o$(TARGET) $(LEXOUT) $(YYTAB_C) $(PILHA_BIB_O) $(COMPILER_FLAGS)

$(PILHA_BIB_O): $(PILHA_BIB_C) $(PILHA_BIB_H)
	$(COMPILER) -c $(PILHA_BIB_C) -o$(PILHA_BIB_O)

$(LEXOUT): $(LEXFILE) $(YYTAB_C)
	$(FLEX) -o$(LEXOUT) $(LEXFILE)

$(YYTAB_C): $(YACCFILE)
	$(BISON) -o$(YYTAB_C) -dy $(YACCFILE)

# Executa o script de teste

test: all
	$(BASH) $(TEST_SCRIPT)

# Compactação dos arquivos do projeto em zip
# Executa a limpeza dos arquivos antes de "zipar"

zip: clean
	$(ZIP) -R $(ZIPFILE) Makefile $(EXTENSIONS)

# Limpeza dos arquivos do projeto gerados pelo make

clean:
	$(RM) $(YYTAB_C)
	$(RM) $(YYTAB_H)
	$(RM) $(LEXOUT)
	$(RM) ./$(TARGET)
	$(RM) $(DIRECTORY)/*.o
	$(RM) ./$(ZIPFILE)
