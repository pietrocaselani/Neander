//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_NOT_H
#define NEANDER_NOT_H

#include "IInstruction.h"

namespace Neander {
	class NOT : public IInstruction {
	public:
			virtual ~NOT();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_NOT_H
