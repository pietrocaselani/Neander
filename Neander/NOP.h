//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_NOP_H
#define NEANDER_NOP_H

#include "IInstruction.h"

namespace Neander {
	class NOP : public IInstruction {
	public:
			virtual ~NOP();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_NOP_H
