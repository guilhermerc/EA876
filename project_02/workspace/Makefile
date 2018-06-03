# @ - rule's name
# < - dependencies' name

# Compilation macros
CC = gcc
CC_FLAGS = -Wextra
SRC_DIR = src
LIBRARY_DIR = lib
MAIN_C = $(SRC_DIR)/main.c
IMAGE_IO_LIB_H = $(LIBRARY_DIR)/image_io_lib.h
IMAGE_IO_LIB_C = $(LIBRARY_DIR)/image_io_lib.c
IMAGE_IO_LIB_0 = $(LIBRARY_DIR)/image_io_lib.o
# SINGLETHREAD_LIB.H = $(LIBRARY_DIR)/singlethread_lib.h
# SINGLETHREAD_LIB.C = $(LIBRARY_DIR)/singlethread_lib.c
# MULTITHREAD_LIB.H = $(LIBRARY_DIR)/multithread_lib.h
# MULTITHREAD_LIB.C = $(LIBRARY_DIR)/multithread_lib.c
# MULTIPROCESS_LIB.H = $(LIBRARY_DIR)/multiprocess_lib.h
# MULTIPROCESS_LIB.C = $(LIBRARY_DIR)/multiprocess_lib.c
CONVOLUTION_LIB_H = $(LIBRARY_DIR)/convolution_lib.h
CONVOLUTION_LIB_C = $(LIBRARY_DIR)/convolution_lib.c
CONVOLUTION_LIB_0 = $(LIBRARY_DIR)/convolution_lib.o
TARGET_C = main 
BJS = $(SRCS:.c=.o)

# Test macros
BASH = sh
TEST_SCRIPT = test.sh

# Zip building macros
ZIP = zip
NOME_PROJETO = trabalho_01
ZIPFILE = $(NOME_PROJETO).zip
EXTENSIONS = *.c *.h *.java *.py *.csv *.xml *.sh

.PHONY: depend clean

all: $(TARGET_C)

$(TARGET_C): $(CONVOLUTION_LIB_0) $(IMAGE_IO_LIB_0) $(MAIN_C)
	$(CC) -o$(TARGET_C) $(MAIN_C) $(CONVOLUTION_LIB_0) $(IMAGE_IO_LIB_0) $(CC_FLAGS) -I./include/ -lfreeimage

$(CONVOLUTION_LIB_0): $(CONVOLUTION_LIB_C)
	$(CC) -c $< $(CC_FLAGS) -I./include/ -o $@	

$(IMAGE_IO_LIB_0): $(IMAGE_IO_LIB_C)
	$(CC) -c $< $(CC_FLAGS) -I./include/ -o $@	

# Executa o script de teste

_test: all
	$(BASH) $(TEST_SCRIPT)

# Compactação dos arquivos do projeto em zip
# Executa a limpeza dos arquivos antes de "zipar"

_zip: clean
	$(ZIP) -R $(ZIPFILE) Makefile $(EXTENSIONS)

# Limpeza dos arquivos do projeto gerados pelo make

_clean:
	$(RM) $(YYTAB_C)
	$(RM) $(YYTAB_H)
	$(RM) $(LEXOUT)
	$(RM) ./$(TARGET_C)
	$(RM) $(LIBRARY_DIR)/*.o
	$(RM) ./$(ZIPFILE)
	$(RM) ./*.class
