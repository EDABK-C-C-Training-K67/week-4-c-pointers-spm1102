CC := gcc

ifeq ($(OS),Windows_NT)
GRADER_DIR := grader/win
EXE_EXTENSION := .exe
GRADER_EXTENSION := .ps1
GRADER_COMMAND := powershell.exe
BUILD_DIR_FLAG := "-ErrorAction SilentlyContinue | Out-Null"
else
GRADER_DIR := grader/linux
EXE_EXTENSION := .out
GRADER_EXTENSION := .sh
GRADER_COMMAND :=
BUILD_DIR_FLAG :=
ALLOW_PERMISSION_COMMAND := chmod +x
endif

.PHONY: all $(TASKS)

TASKS := task1_0 task2_1 task2_2

all: $(TASKS)

clean:
	@$(GRADER_COMMAND) rm -r build

define task_template
$(1): src/$(1).c
	@-$(GRADER_COMMAND) mkdir build $(BUILD_DIR_FLAG) || true
	@echo "Compiling $(1)..."
	@-$(CC) -Wall src/$(1).c -o build/$(1)$(EXE_EXTENSION)
	@echo "Running $(1)..."
ifeq ($(OS),Windows_NT)
else
	@-$(ALLOW_PERMISSION_COMMAND) ./$(GRADER_DIR)/$(1)$(GRADER_EXTENSION)
endif
	@-$(GRADER_COMMAND) ./$(GRADER_DIR)/$(1)$(GRADER_EXTENSION)
endef


$(foreach task, $(TASKS), $(eval $(call task_template,$(task))))