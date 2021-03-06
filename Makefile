 #########################################################################################
 #                                                                                       #
 # Copyright (C) 2016 LAZARE Lucas (lazarelucas@yahoo.fr)                                #
 #                                                                                       #
 # This software is provided 'as-is', WITHOUT ANY EXPRESS OR IMPLIED WARRANTY.           #
 # In NO EVENT will the authors be held liable for any damages arising from the          #
 # use of this software.                                                                 #
 #                                                                                       #
 # Permission is granted to anyone to use this software for any purpose,                 #
 # including commercial applications, and to alter it and redistribute it freely,        #
 # subject to the following restrictions:                                                #
 #                                                                                       #
 # 1. The origin of this software must not be misrepresented;                            #
 # you must not claim that you wrote the original software.                              #
 # If you use this software in a product, an acknowledgment                              #
 # in the product documentation would be appreciated but is not required.                #
 #                                                                                       #
 # 2. Altered source versions must be plainly marked as such,                            #
 # and must not be misrepresented as being the original software.                        #
 #                                                                                       #
 # 3. This notice may not be removed or altered from any source distribution.            #
 #                                                                                       #
 #########################################################################################


FILEIDENTIFIER = .cpp
COMPILER       = g++
COMPFLAGS      =  -Wdisabled-optimization -Winvalid-pch -Wunused -Wconversion -Wlogical-op -Wuninitialized -Wdouble-promotion -Wformat -Wmissing-include-dirs -Wall -pedantic -pedantic-errors -Wmain -Wswitch-default -Wunreachable-code -Winline -Wfloat-equal -Wundef -Wcast-align -Wredundant-decls -Winit-self -Wshadow -Wnon-virtual-dtor -O3 -Wswitch-enum -Wmissing-declarations
DEFINES        =
COMPSTANDARD   = -std=c++0x
DEBUGGER       = gdb
LEAKCHECKER    = valgrind --leak-check=full --show-leak-kinds=all
DISPLAY        = printf
MKDIR          = mkdir -p
RMDIR          = rmdir
RM             = rm -f
RECURSERM      = rm -rf
LD             = ld -r
RECURSECP      = cp -rf
CD             = cd
CHMOD          = chmod +x
VOIDECHO       = > /dev/null 2>&1
BUILDDIR       = build/
INSTALLDIR     = /usr/local/share/PapraGame
INSTALLCMD	   = /usr/local/bin/papragame
OBJDIR         = obj/
SOURCEDIR      = src/
INCLUDEDIR     = -I/usr/include -Iinclude/
LIBSDIR        = -L/usr/lib
SOURCENAME     = Coord Ducky Duck Map Game NetworkGame Menu MapEditor main
EXENAME        = PapraGame
LINKS          = -lstdc++ -lsfml-audio -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system

SHOWDONES      = 1

EXEFINALOBJ    = $(OBJDIR)$(EXENAME).o
EXEFINAL       = $(BUILDDIR)$(EXENAME).elf
SOURCES        = $(foreach src,$(SOURCENAME),$(SOURCEDIR)$(src)$(FILEIDENTIFIER))
OBJECTS        = $(foreach src,$(SOURCENAME),$(OBJDIR)$(src).o)
VPATH          = $(SOURCEDIR)
COMPFLAGS     += $(COMPSTANDARD)

CHARACTERS := A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
CHARACTERS += a b c d e f g h i j k l m n o p q r s t u v w x y z
CHARACTERS += 0 1 2 3 4 5 6 7 8 9 / \\ - _ . + \ 
STRLEN = $(strip $(eval __temp := $(subst $(sp),x,$1))$(foreach a,$(CHARACTERS),$(eval __temp := $$(subst $a,x,$(__temp))))$(eval __temp := $(subst x,x ,$(__temp)))$(words $(__temp)))

.PHONY: silent
silent:
	@make --silent $(EXEFINAL)

.PHONY: fast
fast:
	@make --silent -j8 -B nodones

.PHONY: nodones
nodones: SHOWDONES = 0
nodones: $(EXEFINAL)

.PHONY: all
all: $(EXEFINAL)

.PHONY: $(EXENAME)
$(EXENAME): $(EXEFINAL)

$(EXEFINAL): $(EXEFINALOBJ)
	@$(DISPLAY) "\n\033[1m\033[92m+\033[0m Building \033[33m$(EXEFINAL)\033[0m from \033[33m$(OBJDIR)$(EXENAME).o\033[0m..."
	@$(MKDIR) $(BUILDDIR)
	$(COMPILER) $(EXEFINALOBJ) $(LIBSDIR) $(LINKS) -o $(EXEFINAL)
	@if [ $(SHOWDONES) -eq 1 ]; then for i in `seq 1 $(shell expr 65 - $(call STRLEN,$(OBJDIR)$(EXENAME).o) - $(call STRLEN,$(EXEFINAL)))`; do $(DISPLAY) " "; done; $(DISPLAY) " -> Done"; fi
	@$(DISPLAY) "\n\n"

$(EXEFINALOBJ): $(OBJECTS)
	@$(DISPLAY) "\n\n\033[1m\033[92m+\033[0m Merging objects files into \033[33m$(EXEFINALOBJ)\033[0m..."
	$(LD) $(OBJECTS) -o $(EXEFINALOBJ)
	@if [ $(SHOWDONES) -eq 1 ]; then for i in `seq 1 $(shell expr 52 - $(call STRLEN,$(EXEFINALOBJ)))`; do $(DISPLAY) " "; done; $(DISPLAY) " -> Done"; fi
	@$(DISPLAY) "\n"


$(OBJDIR)%.o: %$(FILEIDENTIFIER)
	@$(DISPLAY) "\n\033[1m\033[92m+\033[0m Building \033[33m$@\033[0m from \033[33m$^\033[0m..."
	@$(MKDIR) $(OBJDIR)
	$(COMPILER) $(COMPFLAGS) $(INCLUDEDIR) $(DEFINES) -c $^ -o $@
	@if [ $(SHOWDONES) -eq 1 ]; then for i in `seq 1 $(shell expr 65 - $(call STRLEN,$^) - $(call STRLEN,$@))`; do $(DISPLAY) " "; done; $(DISPLAY) " -> Done"; fi

.PHONY: install
install:
	@$(DISPLAY) "\033[0mInstalling...\n"
	@make --silent $(EXEFINAL)
	@$(RECURSECP) $(BUILDDIR) $(INSTALLDIR)
	@$(DISPLAY) "Copying files to \033[33m$(INSTALLDIR)\033[0m...\n"
	@$(DISPLAY) "#!/bin/bash\n$(CD) $(INSTALLDIR)\n./$(EXENAME).elf \"$$" > $(INSTALLCMD)
	@$(DISPLAY) "@\"\n" >> $(INSTALLCMD)
	@$(CHMOD) $(INSTALLCMD)
	@$(DISPLAY) "Done\n"

.PHONY: uninstall
uninstall:
	@$(DISPLAY) "Deleting installed files\n"
	@$(RECURSERM) $(INSTALLDIR)
	@$(RM) $(INSTALLCMD)
	@$(DISPLAY) "Done\n"

.PHONY: debug
debug: COMPFLAGS = -g $(COMPSTANDARD)
debug: $(EXEFINAL)

.PHONY: memleak
memleak: COMPFLAGS = -g $(COMPSTANDARD)
memleak: $(EXEFINAL)

.PHONY: clean
clean:
	@$(DISPLAY) "\033[0mCleaning files and folders...\n"
	@$(RM) $(OBJECTS) $(EXEFINAL) $(EXEFINALOBJ)
	@$(RMDIR) $(OBJDIR) $(VOIDECHO) || true
	@$(DISPLAY) "Done\n"
