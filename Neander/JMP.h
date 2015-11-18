//
// Created by Pietro Caselani on 11/14/15.
//

#ifndef NEANDER_JMP_H
#define NEANDER_JMP_H

#include "IInstruction.h"

namespace Neander {
	class JMP : public IInstruction {
	public:
			virtual ~JMP();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_JMP_H
