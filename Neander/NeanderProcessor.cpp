//
// Created by Pietro Caselani on 11/13/15.
//

#include "NeanderProcessor.h"
#include "NOP.h"
#include "STA.h"
#include "LDA.h"
#include "HLT.h"
#include "NOT.h"
#include "OR.h"
#include "AND.h"
#include "ADD.h"
#include "JMP.h"
#include "JN.h"
#include "JZ.h"

using namespace Neander;

NeanderProcessor::NeanderProcessor() {
	mInstructions.push_back(makeInstruction<NOP>());
	mInstructions.push_back(makeInstruction<STA>());
	mInstructions.push_back(makeInstruction<LDA>());
	mInstructions.push_back(makeInstruction<ADD>());
	mInstructions.push_back(makeInstruction<NOT>());
	mInstructions.push_back(makeInstruction<OR>());
	mInstructions.push_back(makeInstruction<AND>());
	mInstructions.push_back(makeInstruction<JMP>());
	mInstructions.push_back(makeInstruction<JZ>());
	mInstructions.push_back(makeInstruction<JN>());
	mInstructions.push_back(makeInstruction<HLT>());
}

NeanderProcessor::~NeanderProcessor() { }

const MemoryPtr &NeanderProcessor::getMemory() const {
	return mMemory;
}

const AccumulatorPtr &NeanderProcessor::getAccumulator() const {
	return mAccumulator;
}

const ProgramCounterPtr &NeanderProcessor::getProgramCounter() const {
	return mProgramCounter;
}

void NeanderProcessor::load(const MemoryPtr &memory) {
	mMemory = memory;
	mAccumulator = make_shared<Accumulator>();
	mProgramCounter = make_shared<ProgramCounter>();
}

void NeanderProcessor::process() {
	for (unsigned long i = 0, size = mMemory->size(); i < size; ++i) {
		auto value = mMemory->getValue(mProgramCounter->getAddress());
		auto instruction = findInstruction(value);
		if (instruction != nullptr) {
			instruction->execute(mMemory, mAccumulator, mProgramCounter);

			mStatus = mAccumulator->getValue() == 0 ? Status::ZERO :
								mMemory->isNegativeValue(mAccumulator->getValue()) ? Status::NEGATIVE :
								Status::NONE;

			if (instruction->getCode() == 240) break;
		}
	}
}

const IInstructionPtr NeanderProcessor::findInstruction(int value) const {
	IInstructionPtr result = nullptr;

	for (unsigned long i = 0, size = mInstructions.size(); i < size; ++i) {
		auto instruction = mInstructions.at(i);
		if (instruction->getCode() == value) {
			result = instruction;
			break;
		}
	}

	return result;
}

const Status &NeanderProcessor::getStatus() const {
	return mStatus;
}
