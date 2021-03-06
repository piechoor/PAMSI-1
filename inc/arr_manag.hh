#pragma once
#include <chrono>
#include <iostream>
#include <math.h>
#include <fstream>

#define REGISTER_FILE "register_excel.txt"
#define REG_FORM_HUMAN false

bool RunTest(int noElems, float sortLvl);

int* InitArr(int size, float sortLvl);

void WriteToReg(int noElems, float sortLvl, float time);

bool isSorted(int* arr, int size);

