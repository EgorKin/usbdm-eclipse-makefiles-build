# Build list for Flash Programmer
SRC += Version.rc

# List source file to include from current directory
SRC += TestFlashImage.cpp

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS  += -I$(SHARED_SRC)
