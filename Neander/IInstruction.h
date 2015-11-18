//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_IINSTRUCTION_H
#define NEANDER_IINSTRUCTION_H

#include <string>
#include "Accumulator.h"
#include "ProgramCounter.h"
#include "Memory.h"

using namespace std;

namespace Neander {

	class Memory;

	typedef shared_ptr<Memory> MemoryPtr;

	class IInstruction {
	public:
			virtual ~IInstruction() { }

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) = 0;

			virtual string getName() = 0;

			virtual int getCode() = 0;
	};
}

#endif //NEANDER_IINSTRUCTION_H
