TARGET = test.rom
LICENSEE = SI # up to 2 chars
GAME_ID = TEST # up to 4 chars
TITLE = TEST # up to 16 chars

ASSEMBLER = rgbasm
LINKER = rgblink
FIXER = rgbfix

ASSEMBLER_FLAGS = -Wall -Wno-numeric-string -H -l $(patsubst %,-i %, $(INC_DIR))
LINKER_FLAGS = 
FIXER_FLAGS = -vC -i $(GAME_ID) -t $(TITLE) -k $(LICENSEE) -l 0x33 -n 0x00 -m 0x1B -r 0xFF -p 0xFF

SRC_DIR = ./src
INC_DIR = ./inc ./data/inc ./data/bin
TEMP_DIR = ./temp
OUT_DIR = ./out

#processes source files with depth of up to three folders
SRC := $(wildcard $(SRC_DIR)/*.gbasm) $(wildcard $(SRC_DIR)/*/*.gbasm) $(wildcard $(SRC_DIR)/*/*/*.gbasm)
OBJ := $(patsubst $(SRC_DIR)/%.gbasm, $(TEMP_DIR)/%.o, $(SRC))
TEMP_DIR_TREE := $(dir $(OBJ))

default: setup assemble link fix clean

setup:
	mkdir -p $(TEMP_DIR_TREE)
	mkdir -p $(OUT_DIR)

assemble: $(OBJ)

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.gbasm
	$(ASSEMBLER) $(ASSEMBLER_FLAGS) -o $@ $<

link:
	$(LINKER) $(LINKER_FLAGS) -o $(OUT_DIR)/$(TARGET) $(OBJ)

fix:
	$(FIXER) $(FIXER_FLAGS) $(OUT_DIR)/$(TARGET)

clean:
	rm -rf $(TEMP_DIR)
