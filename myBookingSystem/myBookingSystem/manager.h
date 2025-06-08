#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>

void exitMessage();
void centerText(std::string text);
void clearScreen();
void fullScreen();
void print(const std::string& filename);
void paddingUp(int paddingSize);
int getConsoleWidth();