
CC = gcc

BUILD_DIR = build

LIB_DIR = src/math
CLI_DIR = src/cli

EXE = $(BUILD_DIR)/calculator

SRC = \
src/calculator.c \
src/math/my_add.c \
src/math/my_sub.c \
src/math/my_mul.c \
src/math/my_div.c \
src/cli/cli_input.c

CINC = \
-Iinc \
-Iinc/math \
-Iinc/cli

CCFLAGS = \
-fPIC

LDFLAGS = \
-ldl \
-Wl,-rpath,./$(BUILD_DIR)

OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.o)))
vpath %.c $(dir $(SRC))
vpath %.o $(BUILD_DIR)

LIB_OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(filter $(LIB_DIR)/%,$(SRC:.c=.o))))
CLI_OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(filter $(CLI_DIR)/%,$(SRC:.c=.o))))
DINAMIC_LIB = $(addprefix $(BUILD_DIR)/lib,$(notdir $(filter $(LIB_DIR)/%,$(SRC:.c=.so))))
MAIN_OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(filter-out $(LIB_DIR)/%,$(SRC:.c=.o))))

all: $(BUILD_DIR) $(OBJ) $(DINAMIC_LIB) $(EXE)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(OBJ): $(BUILD_DIR)/%.o: %.c
	$(CC) $(CCFLAGS) $(CINC) -c $< -o $@

$(BUILD_DIR)/lib%.so: %.o
	$(CC) -shared -o $@ $^ $(CLI_OBJ)

$(EXE): $(MAIN_OBJ) $(CLI_OBJ)
	$(CC) $(CINC) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

run:
	./$(EXE)
