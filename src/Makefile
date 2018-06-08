VPATH = ./libs:../includes
OBJS_DIR = .objs
EXE_DIR = ..
LIBS_DIR = libs
EXE_NN=nn
# add more libraries here if necessary
OBJS_NN=$(EXE_NN).o

## COMPILER
# using gcc over clang because of pre-fetching optimization that is coming eventually
CC = g++ 
WARNINGS = -Wall -Wextra -Werror -Wno-error=unused-parameter
INC=-I./libs/ -I../includes/
CFLAGS_DEBUG   = -O0 $(WARNINGS) $(INC) -g -std=c++11 -c -MMD -MP -pthread -DDEBUG
CFLAGS_RELEASE = -O2 $(WARNINGS) $(INC) -g -std=c++11 -c -MMD -MP -pthread

## LINKER
# eventually I would like to use a static library here
LD = g++
LDFLAGS = -pthread -lm

# PHONY declarations
.PHONY: all
.PHONY: debug
.PHONY: release
.PHONY: clean

## BUILD TARGETS
# if cp fails in pre-build then remove any of the files that was already copied
all:
	@($(MAKE) --no-print-directory pre-build && $(MAKE) --no-print-directory post-build) || $(MAKE) --no-print-directory failed

### Update: 11/9/2017 using VPATH now ###
pre-build:
	@echo "Build Start!"

post-build: release
	@echo "Build Success!"
	@echo "Removing .obj directory"
	@rm -r ./$(OBJS_DIR)
	@echo "Clean up Success!"

failed:	
	@echo "Something went wrong :/"
	@-rm -r ./$(OBJS_DIR)

release: $(EXE_DIR)/$(EXE_NN)

debug: clean
	($(MAKE) --no-print-directory pre-build-debug && $(MAKE) --no-print-directory post-build-debug) || $(MAKE) --no-print-directory failed

pre-build-debug:
	@echo "Debug Build Start!"

post-build-debug: $(EXE_DIR)/$(EXE_NN:%=%-debug)
	@echo "Debug Build Success!"
	rm -r ./$(OBJS_DIR)

## OBJECTS
-include $(OBJS_DIR)/*.d
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%-debug.o: %.cpp | $(OBJS_DIR)
	@mkdir -p $(basename $@)
	$(CC) $(CFLAGS_DEBUG) $< -o $@

$(OBJS_DIR)/%-release.o: %.cpp | $(OBJS_DIR)
	@mkdir -p $(basename $@)
	$(CC)  $(CFLAGS_RELEASE) $< -o $@

## EXES
$(EXE_DIR)/$(EXE_NN): $(OBJS_NN:%.o=$(OBJS_DIR)/%-release.o)
	$(LD) $^ $(LDFLAGS) -o $@

$(EXE_DIR)/$(EXE_NN)-debug: $(OBJS_NN:%.o=$(OBJS_DIR)/%-debug.o)
	$(LD) $^ $(LDFLAGS) -o $@

## CLEAN
clean:
	-rm -rf .objs $(EXE_DIR)/$(EXE_NN) $(EXE_DIR)/$(EXE_NN:%=%-debug)
