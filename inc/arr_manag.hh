#pragma once
#include <chrono>
#include <iostream>

#define REGISTER_FILE "register.txt"

bool RunTest(unsigned int noElems, int sortLvl);

int* InitArr(unsigned int size);

void SortToLvl(int arr[], int lvl, int);

bool WriteToReg(int noElems, int sortLvl, float time);

