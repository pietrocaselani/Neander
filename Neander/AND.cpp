//
// Created by Pietro Caselani on 11/14/15.
//

#include "AND.h"

using namespace Neander;

AND::~AND() {}

void AND::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	auto value = memory->getValue(memory->getValue(pc->incrementAddress()));
	accumulator->setValue(accumulator->getValue() & value);

	pc->incrementAddress();
}

string AND::getName() {
	return "AND";
}

int AND::getCode() {
	return 80;
}
