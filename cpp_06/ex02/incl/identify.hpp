#pragma once
#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);
