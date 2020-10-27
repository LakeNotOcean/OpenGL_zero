#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include "global.h"

using namespace std;

struct slash_is_space : std::ctype<char> {
    slash_is_space();
    static mask const* get_table();
};

void loadInput(string fileName, vector<Vector3f> &vecv, vector<Vector3f> &vecn, vector<face> &vecf);
