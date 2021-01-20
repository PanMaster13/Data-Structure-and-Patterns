#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Zipperman : public Animal
{
public:
	void howMove();
	void howCall();
};
