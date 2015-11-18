//
// Created by Pietro Caselani on 11/13/15.
//

#include "ProgramCounter.h"

using namespace Neander;

ProgramCounter::ProgramCounter() : ProgramCounter(0) {}

ProgramCounter::ProgramCounter(unsigned long address) {
	mAddress = address;
}

unsigned long ProgramCounter::getAddress() const {
	return mAddress;
}

void ProgramCounter::setAddress(unsigned long address) {
	mAddress = address;
}

unsigned long ProgramCounter::incrementAddress() {
	return ++mAddress;
}
