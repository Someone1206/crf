@echo off
rem Requirements: g++ and added to path

set BIN_DIR=bin
IF exist %BIN_DIR% (
	rem do nothing
) ELSE (
	mkdir %BIN_DIR% 
	echo %BIN_DIR% created
)
rem extension doesn't matter. Yes, '.exe' doesn't matter in windows
rem but giving it to make to CLEAR that its a Windows executable
@echo on
g++ main.cpp -o %BIN_DIR%\crf.exe -std=c++17