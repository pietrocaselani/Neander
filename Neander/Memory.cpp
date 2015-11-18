//
// Created by Pietro Caselani on 11/13/15.
//

#include "Memory.h"

#define DEFAULT_VALUE 0

using namespace Neander;

Memory::Memory() {
	setTotal(256);
	mInnerPosition = 0;
}

const AddressesPtr &Memory::getAddresses() const {
	return mAddresses;
}

unsigned long Memory::getTotal() const {
	return mTotal;
}

void Memory::setTotal(unsigned long total) {
	mTotal = total;

	auto addresses = new Addresses(total);

	mAddresses = shared_ptr<Addresses>(addresses);
}

const void Memory::addInstruction(IInstructionPtr instruction) {
	addInstruction(mInnerPosition++, instruction);
}

const void Memory::addInstruction(unsigned long memoryPosition, IInstructionPtr instruction) {
	addValue(memoryPosition, (unsigned long) instruction->getCode());
}

const void Memory::addValue(unsigned long value) {
	return addValue(mInnerPosition++, value);
}

const bool Memory::isPositionValid(unsigned long position) const {
	return position <= getMaxPosition();
}

const bool Memory::isNegativeValue(unsigned long value) const {
	return value > getMaxPosition() / 2;
}

const unsigned long Memory::getValue(unsigned long position) const {
	checkPosition(position);
	return mAddresses->at(position);
}

const void Memory::addValue(unsigned long position, unsigned long value) {
	checkPosition(position);
	mAddresses->at(position) = value;
}

const void Memory::checkPosition(unsigned long position) const {
	if (!isPositionValid(position)) throw runtime_error("Invalid memory position");
}

const unsigned long Memory::size() const {
	return mAddresses->size();
}

unsigned long Memory::getMinPosition() const {
	return 0;
}

unsigned long Memory::getMaxPosition() const {
	return mTotal - 1;
}
