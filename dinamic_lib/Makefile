
CC = gcc

BUILD_DIR = build

LIB_DIR = src/math

EXE = $(BUILD_DIR)/calculator

DINAMIC_LIB = My_math

SRC = \
src/calculator.c \
src/math/my_math.c \
src/math/cli_input.c

CINC = \
-Iinc \
-Iinc/math

CCFLAGS = \
-fPIC

LDFLAGS = \
-Xlinker \
-rpath=$(shell pwd)/$(BUILD_DIR)

LIBS = \
-l$(DINAMIC_LIB)

OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.o)))
vpath %.c $(dir $(SRC))

LIB_OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(filter $(LIB_DIR)/%,$(SRC:.c=.o))))
MAIN_OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(filter-out $(LIB_DIR)/%,$(SRC:.c=.o))))

all: $(BUILD_DIR) $(EXE)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(OBJ): $(BUILD_DIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $(CINC) $< -o $@

lib$(DINAMIC_LIB).so: $(LIB_OBJ)
	$(CC) -shared -o$(BUILD_DIR)/$@ $^

$(EXE): $(MAIN_OBJ) lib$(DINAMIC_LIB).so
	$(CC) $(CINC) $< -L$(BUILD_DIR) $(LIBS) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)

run:
	./$(EXE)
