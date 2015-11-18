//
// Created by Pietro Caselani on 11/13/15.
//

#include <iostream>
#include "HLT.h"

using namespace Neander;

HLT::~HLT() {}

void HLT::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	pc->incrementAddress();
}

string HLT::getName() {
	return "HLT";
}

int HLT::getCode() {
	return 240;
}
