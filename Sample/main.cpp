#include <iostream>
#include "NeanderProcessor.h"
#include "LDA.h"
#include "NOT.h"
#include "ADD.h"
#include "HLT.h"
#include "JMP.h"
#include "JN.h"
#include "JZ.h"
#include "STA.h"

using namespace std;
using namespace Neander;

void subtraction();
void division();

int main() {
	subtraction();
	division();

	return 0;
}

void subtraction() {
	cout << "\n\n---- Subtraction ----" << endl;

	auto minuend = 10;
	auto subtrahend = 3;

	auto memory = make_shared<Memory>();

	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(129);
	memory->addInstruction(makeInstruction<NOT>());
	memory->addInstruction(makeInstruction<ADD>());
	memory->addValue(130);
	memory->addInstruction(makeInstruction<ADD>());
	memory->addValue(128);
	memory->addInstruction(makeInstruction<HLT>());

	memory->addValue(128, minuend);
	memory->addValue(129, subtrahend);
	memory->addValue(130, 1);

	auto processor = make_shared<NeanderProcessor>();
	processor->load(memory);
	processor->process();

	cout << "Accumulator: " << processor->getAccumulator()->getValue() << endl;
	cout << "Program Counter: " << processor->getProgramCounter()->getAddress() << endl;

	cout << "---- Subtraction end ----" << endl;
}

void division() {
	cout << "\n\n---- Division ----" << endl;

	auto dividend = 8;
	auto divider = 5;

	auto memory = make_shared<Memory>();

	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(1);
	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(129);
	memory->addInstruction(makeInstruction<NOT>());
	memory->addInstruction(makeInstruction<ADD>());
	memory->addValue(1);
	memory->addInstruction(makeInstruction<STA>());
	memory->addValue(129);
	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(128);
	memory->addInstruction(makeInstruction<ADD>());
	memory->addValue(129);
	memory->addInstruction(makeInstruction<STA>());
	memory->addValue(128);
	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(130);
	memory->addInstruction(makeInstruction<ADD>());
	memory->addValue(1);
	memory->addInstruction(makeInstruction<STA>());
	memory->addValue(130);
	memory->addInstruction(makeInstruction<LDA>());
	memory->addValue(128);
	memory->addInstruction(makeInstruction<JN>());
	memory->addValue(29);
	memory->addInstruction(makeInstruction<JZ>());
	memory->addValue(29);
	memory->addInstruction(makeInstruction<JMP>());
	memory->addValue(11);
	memory->addInstruction(makeInstruction<HLT>());

	memory->addValue(128, dividend);
	memory->addValue(129, divider);

	auto processor = make_shared<NeanderProcessor>();
	processor->load(memory);
	processor->process();

	cout << "Accumulator: " << processor->getAccumulator()->getValue() << endl;
	cout << "Program Counter: " << processor->getProgramCounter()->getAddress() << endl;
	cout << "Result: " << memory->getValue(130) << endl;

	cout << "---- Division end ----" << endl;
}