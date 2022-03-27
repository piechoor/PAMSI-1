#pragma once
#include <chrono>
#include <iostream>
#include <algorithm>
#include <fstream>

#define REGISTER_FILE "register.txt"
#define REG_FORM 'H' //H for human; E for excel

bool RunTest(unsigned int noElems, float sortLvl);

int* InitArr(unsigned int size, float sortLvl);

bool WriteToReg(int noElems, float sortLvl, float time);

