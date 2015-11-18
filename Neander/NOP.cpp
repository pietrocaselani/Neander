//
// Created by Pietro Caselani on 11/13/15.
//

#include <iostream>
#include "NOP.h"

using namespace Neander;

NOP::~NOP() {}

void NOP::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	pc->incrementAddress();
}

string NOP::getName() {
	return "NOP";
}

int NOP::getCode() {
	return 0;
}
