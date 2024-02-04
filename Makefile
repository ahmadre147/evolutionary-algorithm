# Main target
TARGET := ea

# Roots
ROOT_DIR := .
INC_DIR := $(ROOT_DIR)
SRC_DIR := $(ROOT_DIR)
OBJ_DIR := $(ROOT_DIR)
OUT_DIR := $(ROOT_DIR)

# File extensions
CXX_EXT := cc
OBJ_EXT := o
DUMP_EXT := vcd

# Sources & Objects
SRCS := $(wildcard $(SRC_DIR)/*.$(CXX_EXT))
OBJS := $(SRCS:$(SRC_DIR)/%.$(CXX_EXT)=$(OBJ_DIR)/%.$(OBJ_EXT))

# Compilers
CXX := g++
LD := $(CXX)

# Library versions
SC_VERSION := 2.3.4

# Compiler options
CXX_FLAGS := -I$(INC_DIR)
CXX_FLAGS += -g -O0
CXX_FLAGS += -Iinclude
C_FLAGS += -Wall
LIBS := -lm -lsystemc

# System paths
SC_PATH := /usr/local/systemc-$(SC_VERSION)
LL_64_PATH := $(SC_PATH)/lib-linux64
SC_INC_PATH := $(SC_PATH)/include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -L$(LL_64_PATH) -Wl,-rpath $(LL_64_PATH) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(CXX_EXT)
	$(CXX) $(CXX_FLAGS) $(C_FLAGS) -I$(SC_INC_PATH) -L$(ROOT_DIR) -c $< -o $@

test:$(TARGET)
	./$(TARGET) 

clean:
	$(RM) $(TARGET) *.$(OBJ_EXT) *.$(DUMP_EXT)
.PHONY: $(TARGET)
