//
// Created by Pietro Caselani on 11/14/15.
//

#include "JN.h"

using namespace Neander;

JN::~JN() { }

void JN::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	pc->setAddress(memory->isNegativeValue(accumulator->getValue()) ? memory->getValue(pc->getAddress() + 1) : pc->getAddress() + 2);
}

string JN::getName() {
	return "JN";
}

int JN::getCode() {
	return 144;
}
