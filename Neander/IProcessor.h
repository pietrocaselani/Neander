//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_IPROCESSOR_H
#define NEANDER_IPROCESSOR_H

#include "Accumulator.h"
#include "ProgramCounter.h"
#include "Memory.h"

using namespace std;

namespace Neander {

	enum Status { NONE, NEGATIVE, ZERO };

	class IProcessor {
	public:
			virtual ~IProcessor() {}

			virtual const MemoryPtr &getMemory() const = 0;
			virtual const AccumulatorPtr &getAccumulator() const = 0;
			virtual const ProgramCounterPtr &getProgramCounter() const = 0;

			virtual const Status &getStatus() const = 0;

			virtual void load(const MemoryPtr &memory) = 0;
			virtual void process() = 0;
	};
}

#endif //NEANDER_IPROCESSOR_H
