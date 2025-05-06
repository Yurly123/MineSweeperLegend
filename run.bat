@echo off
REM Compile all C files in the current directory and run the program

REM Set compiler and output file name
SET CC=gcc
SET OUTPUT=MineSweeperLegend.exe
SET CFLAGS=-Wall -Wextra

REM Check if compiler exists
WHERE %CC% >nul 2>nul
IF %ERRORLEVEL% NEQ 0 (
  echo Error: Compiler not found. Please ensure %CC% is installed and in your PATH.
  exit /b 1
)

REM Clean previous build files if they exist
IF EXIST %OUTPUT% del %OUTPUT%
IF EXIST *.o del *.o

REM Compile all .c files to object files
echo Compiling C files...
FOR %%F IN (*.c) DO (
  echo   Compiling %%F...
  %CC% %CFLAGS% -c %%F -o %%~nF.o
  IF ERRORLEVEL 1 (
    echo Error compiling %%F
    exit /b 1
  )
)

REM Link all object files together
echo Linking object files...
%CC% -o %OUTPUT% *.o
IF ERRORLEVEL 1 (
  echo Error during linking
  exit /b 1
)

REM Clean up object files
echo Cleaning up...
del *.o

REM Run the program
echo Running %OUTPUT%...
%OUTPUT%
