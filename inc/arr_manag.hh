#pragma once
#include <chrono>
#include <iostream>
#include <algorithm>
#include <fstream>

#define REGISTER_FILE "register.txt"
#define REG_FORM_HUMAN true

bool RunTest(int noElems, float sortLvl);

int* InitArr(int size, float sortLvl);

void WriteToReg(int noElems, float sortLvl, float time);

bool isSorted(int* arr, int size);

