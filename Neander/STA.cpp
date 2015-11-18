//
// Created by Pietro Caselani on 11/13/15.
//

#include <iostream>
#include "STA.h"

using namespace Neander;

STA::~STA() {}

void STA::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	auto destinationPosition = memory->getValue(pc->incrementAddress());
	memory->addValue(destinationPosition, accumulator->getValue());

	pc->incrementAddress();
}

string STA::getName() {
	return "STA";
}

int STA::getCode() {
	return 16;
}
