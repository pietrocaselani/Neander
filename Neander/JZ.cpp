//
// Created by Pietro Caselani on 11/14/15.
//

#include "JZ.h"

using namespace Neander;

JZ::~JZ() {}

void JZ::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	pc->setAddress(accumulator->getValue() == 0 ? memory->getValue(pc->getAddress() + 1) : pc->getAddress() + 2);
}

string JZ::getName() {
	return "JZ";
}

int JZ::getCode() {
	return 160;
}
