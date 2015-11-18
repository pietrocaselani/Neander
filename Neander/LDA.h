//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_LDA_H
#define NEANDER_LDA_H

#include "IInstruction.h"

namespace Neander {
	class LDA : public IInstruction {
	public:
			virtual ~LDA();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_LDA_H
