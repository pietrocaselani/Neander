//
// Created by Pietro Caselani on 11/14/15.
//

#include "JMP.h"

using namespace Neander;

JMP::~JMP() {}

void JMP::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	pc->setAddress(memory->getValue(pc->getAddress() + 1));
}

string JMP::getName() {
	return "JMP";
}

int JMP::getCode() {
	return 128;
}
