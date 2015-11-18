//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_ADD_H
#define NEANDER_ADD_H

#include "IInstruction.h"

namespace Neander {
	class ADD : public IInstruction {
	public:
			virtual ~ADD();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_ADD_H
