//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_STA_H
#define NEANDER_STA_H

#include "IInstruction.h"

namespace Neander {
	class STA : public IInstruction {
	public:
			virtual ~STA();

			virtual void execute(MemoryPtr memory, AccumulatorPtr accumulator, ProgramCounterPtr pc) override;

			virtual string getName() override;

			virtual int getCode() override;
	};
}

#endif //NEANDER_STA_H
