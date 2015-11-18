//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_JN_H
#define NEANDER_JN_H

#include "IInstruction.h"

namespace Neander {
	class JN : public IInstruction {
	public:
			virtual ~JN();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_JN_H
