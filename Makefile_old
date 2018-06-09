#---Automatically Generated from template 'makefile' wrote by @aliben---
#
# @Copyright (C) 2018 All rights reserved.
# @filename: Makefile
# @author: aliben.develop@gmail.com
# @create_date: 2018-05-31 21:37:15
# @last_modified_date: NO_LAST_MODIFIED_DATE
# @description: TODO
#---****************************************************************---

#----------------------------------------------------------------------
#VARIABLE
  #TEST
    HEAD_POSTFIX=h
    SOURCE_POSTFIX=c

  #COMPILER
    CC=gcc
  #COMPILER_FLAG
    CCFLAG=-Wall -g
    INCLUDEFLAG=-I./include/

  #DIRECTORY
    SOURCE_DIR=./src/
    INCLUDE_DIR=./include/
    BUILD_DIR=./build/
    TEST_DIR=./test/
    OBJECT_DIR=./build/obj/
    BINARY_DIR=./build/bin/

  #SOURCE_LIST
    SOURCE_LIST=scheduler.c
    INCLUDE_LIST=scheduler.h
    TEST_LIST=test_scheduler.c
    OBJECT_LIST=scheduler.o

  #FILE_LIST
    SOURCE_FILE_LIST=./src/scheduler.c
    INCLUDE_FILE_LIST=./include/scheduler.h
    TEST_FILE_LIST=./test/test_scheduler.c
    OBJECT_BUILD_FILE_LIST=./build/obj/scheduler.o ./build/obj/test_scheduler.o

    BINARY_BUILD_FILE_LIST=./build/bin/test_scheduler

#----------------------------!!!!!!!-----------------------------
#---This field should be set while you created your program
  #TARGET_LIST
    TARGET_OBJECT_LIST=scheduler.o
    TEST_OBJECT_LIST=test_scheduler.o
    TARGET_BIN_LIST=
    TEST_BIN_LIST=test_scheduler

  #DEPEND_LIST
    DEP=
#----------------------------!!!!!!!-----------------------------

  #VPATH

#MAKE_KEYWORD
  vpath %.h ./include/
  vpath %.hh ./include/
  vpath %.hpp ./include/
  vpath %.hxx ./include/

  vpath %.c ./src/:./test/
  vpath %.cc ./src/:./test/
  vpath %.cpp ./src/:./test/
  vpath %.cxx ./src/:./test/

#----------------------------------------------------------------------
#TARGET

all: check_build all_obj $(TARGET_BIN_LIST) $(TEST_OBJECT_LIST) $(TEST_BIN_LIST)

all_obj: $(TARGET_OBJECT_LIST)

$(TARGET_OBJECT_LIST): %.o : %.c
	$(CC) $(CCFLAG) -c $< $(INCLUDEFLAG) -o $(OBJECT_DIR)$@

$(TEST_OBJECT_LIST): %.o : %.c
	$(CC) $(CCFLAG) -c $< $(INCLUDEFLAG) -o $(OBJECT_DIR)$@

$(TARGET_BIN_LIST): %: %.o 
	$(CC) $(CCFLAG) $(OBJECT_DIR)$<  $(OBJECT_DIR)$(DEP) -o $(BINARY_DIR)$@ $(INCLUDEFLAG)

$(TEST_BIN_LIST): %: %.o
	$(CC) $(OBJECT_DIR)$< $(OBJECT_DIR)$(OBJECT_LIST) $(INCLUDEFLAG) -o $(BINARY_DIR)$@

.PHONY: clean check_build

check_build:
	if [ ! -e build ]; then mkdir -p build/bin build/obj; fi

clean:
	rm -rf ${OBJECT_BUILD_FILE_LIST}
	rm -rf ${BINARY_BUILD_FILE_LIST}
	rm -rf ${BUILD_DIR}

