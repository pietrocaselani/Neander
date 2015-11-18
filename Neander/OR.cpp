//
// Created by Pietro Caselani on 11/14/15.
//

#include "OR.h"

using namespace Neander;

OR::~OR() {}

void OR::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	auto value = memory->getValue(memory->getValue(pc->incrementAddress()));
	accumulator->setValue(accumulator->getValue() | value);

	pc->incrementAddress();
}

string OR::getName() {
	return "OR";
}

int OR::getCode() {
	return 64;
}
