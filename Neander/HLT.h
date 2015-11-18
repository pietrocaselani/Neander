//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_HLT_H
#define NEANDER_HLT_H

#include "IInstruction.h"

namespace Neander {
	class HLT : public IInstruction {
	public:
			virtual ~HLT();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_HLT_H
