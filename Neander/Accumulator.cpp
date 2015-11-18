//
// Created by Pietro Caselani on 11/13/15.
//

#include "Accumulator.h"

using namespace Neander;

Accumulator::Accumulator() : Accumulator(0) {}

Accumulator::Accumulator(unsigned long value) {
	mValue = value;
}

unsigned long Accumulator::getValue() const {
	return mValue;
}

void Accumulator::setValue(unsigned long value) {
	mValue = value;
}
