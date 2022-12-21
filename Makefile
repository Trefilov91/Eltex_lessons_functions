

CC = gcc
BUILD_DIR = build

EXE += calculator

all: $(BUILD_DIR) $(EXE)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

calculator: calculator.c
	$(CC) $< -o $(BUILD_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)
