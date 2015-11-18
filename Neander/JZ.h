//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_JZ_H
#define NEANDER_JZ_H

#include "IInstruction.h"

namespace Neander {
	class JZ : public IInstruction {
	public:
			virtual ~JZ();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_JZ_H
