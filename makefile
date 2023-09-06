ASSEMBLER = rgbasm
LINKER = rgblink

ASSEMBLER_FLAGS = -Wall -i $(INC_DIR)
LINKER_FLAGS = 

SRC_DIR = ./src
INC_DIR = ./inc
TEMP_DIR = ./temp
OUT_DIR = ./out

TARGET = gb.rom

#processes source files with depth of up to three folders
SRC := $(wildcard $(SRC_DIR)/*.gbasm) $(wildcard $(SRC_DIR)/*/*.gbasm) $(wildcard $(SRC_DIR)/*/*/*.gbasm)
OBJ := $(patsubst $(SRC_DIR)/%.gbasm, $(TEMP_DIR)/%.o, $(SRC))
TEMP_DIR_TREE := $(dir $(OBJ))

default: setup assemble clean

setup:
	mkdir -p $(TEMP_DIR_TREE)
	mkdir -p $(OUT_DIR)

assemble: $(OBJ)
	$(LINKER) $(LINKER_FLAGS) -o $(OUT_DIR)/$(TARGET) $^

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.gbasm
	$(ASSEMBLER) $(ASSEMBLER_FLAGS) -o $@ $<

clean:
	rm -rf $(TEMP_DIR)
