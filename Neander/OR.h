//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_OR_H
#define NEANDER_OR_H

#include "IInstruction.h"

namespace Neander {
	class OR : public IInstruction {
	public:
			virtual ~OR();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_OR_H
