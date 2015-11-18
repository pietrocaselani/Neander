//
// Created by Pietro Caselani on 11/13/15.
//

#include <iostream>
#include "LDA.h"

using namespace Neander;

LDA::~LDA() {}

void LDA::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	auto value = memory->getValue(memory->getValue(pc->incrementAddress()));
	accumulator->setValue(value);

	pc->incrementAddress();
}

string LDA::getName() {
	return "LDA";
}

int LDA::getCode() {
	return 32;
}
