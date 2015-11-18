//
// Created by Pietro Caselani on 11/14/15.
//

#include "ADD.h"

using namespace Neander;

ADD::~ADD() {}

void ADD::execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) {
	auto destinationPosition = memory->getValue(pc->incrementAddress());
	auto sumValue = memory->getValue(destinationPosition);
	auto acValue = accumulator->getValue();

	auto newValue = sumValue + acValue;

	if (memory->isNegativeValue(newValue) && newValue > memory->getMaxPosition()) {
		auto total = memory->getTotal();
		newValue = newValue - total;
	}

	accumulator->setValue(newValue);

	pc->incrementAddress();
}

string ADD::getName() {
	return "ADD";
}

int ADD::getCode() {
	return 48;
}
