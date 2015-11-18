//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_AND_H
#define NEANDER_AND_H

#include "IInstruction.h"

namespace Neander {
	class AND : public IInstruction {
	public:
			virtual ~AND();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_AND_H
