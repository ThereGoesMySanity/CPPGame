#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/src/Dock.o \
	${OBJECTDIR}/src/src/Game.o \
	${OBJECTDIR}/src/src/Graphics.o \
	${OBJECTDIR}/src/src/Input.o \
	${OBJECTDIR}/src/src/Main.o \
	${OBJECTDIR}/src/src/Sprite.o \
	${OBJECTDIR}/src/src/TerminalWindow.o \
	${OBJECTDIR}/src/src/Window.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/src/Dock.o: src/src/Dock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Dock.o src/src/Dock.cpp

${OBJECTDIR}/src/src/Game.o: src/src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Game.o src/src/Game.cpp

${OBJECTDIR}/src/src/Graphics.o: src/src/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Graphics.o src/src/Graphics.cpp

${OBJECTDIR}/src/src/Input.o: src/src/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Input.o src/src/Input.cpp

${OBJECTDIR}/src/src/Main.o: src/src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Main.o src/src/Main.cpp

${OBJECTDIR}/src/src/Sprite.o: src/src/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Sprite.o src/src/Sprite.cpp

${OBJECTDIR}/src/src/TerminalWindow.o: src/src/TerminalWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/TerminalWindow.o src/src/TerminalWindow.cpp

${OBJECTDIR}/src/src/Window.o: src/src/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src/Window.o src/src/Window.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
