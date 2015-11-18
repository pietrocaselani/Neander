//
// Created by Pietro Caselani on 11/14/15.
//

#include "NOT.h"

using namespace Neander;

NOT::~NOT() {}

void NOT::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	accumulator->setValue(memory->getMaxPosition() - accumulator->getValue());
	pc->incrementAddress();
}

string NOT::getName() {
	return "NOT";
}

int NOT::getCode() {
	return 96;
}
