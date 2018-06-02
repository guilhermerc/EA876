#Macros para compilação

C_COMPILER = gcc
C_COMPILER_FLAGS = -Wextra
LIBRARY_DIR = lib
IMAGE_PROCESSING_H = $(LIBRARY_DIR)/image_processing.h
IMAGE_PROCESSING.C = $(LIBRARY_DIR)/image_processing.c
SINGLETHREAD_LIB.H = $(LIBRARY_DIR)/singlethread_lib.h
SINGLETHREAD_LIB.C = $(LIBRARY_DIR)/singlethread_lib.c
MULTITHREAD_LIB.H = $(LIBRARY_DIR)/multithread_lib.h
MULTITHREAD_LIB.C = $(LIBRARY_DIR)/multithread_lib.c
MULTIPROCESS_LIB.H = $(LIBRARY_DIR)/multiprocess_lib.h
MULTIPROCESS_LIB.C = $(LIBRARY_DIR)/multiprocess_lib.c
LEXFILE = $(LIBRARY_DIR)/main.l
TARGET_C = main
BJS = $(SRCS:.c=.o)
BISON = bison
FLEX = flex

JAVA_COMPILER = javac
JAVA_COMPILER_FLAGS = -d .
DIRECTORY_JAVA = src/java
JAVA_FILES = $(DIRECTORY_JAVA)/*.java
TARGET_JAVA = *.class

# Macros para teste

BASH = sh
TEST_SCRIPT = test.sh

# Macros para construção do zip
ZIP = zip
NOME_PROJETO = trabalho_01
ZIPFILE = $(NOME_PROJETO).zip
EXTENSIONS = *.c *.h *.java *.py *.csv *.xml *.sh

.PHONY: depend clean

all: $(TARGET_C) $(TARGET_JAVA)

$(TARGET_JAVA): $(JAVA_FILES)
	$(JAVA_COMPILER) $(JAVA_COMPILER_FLAGS) $(JAVA_FILES)

$(TARGET_C): $(LEXOUT) $(YYTAB_C)
	$(C_COMPILER) -o$(TARGET_C) $(LEXOUT) $(YYTAB_C) $(C_COMPILER_FLAGS)

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
	$(RM) ./$(TARGET_C)
	$(RM) $(LIBRARY_DIR)/*.o
	$(RM) ./$(ZIPFILE)
	$(RM) ./*.class
