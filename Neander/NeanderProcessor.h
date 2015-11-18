//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_NEANDERPROCESSOR_H
#define NEANDER_NEANDERPROCESSOR_H

#include "IProcessor.h"
#include "ProgramCounter.h"
#include "Accumulator.h"

namespace Neander {
	class NeanderProcessor : public IProcessor {
	private:
			MemoryPtr mMemory;
			AccumulatorPtr mAccumulator;
			ProgramCounterPtr mProgramCounter;
			vector<IInstructionPtr> mInstructions;
			Status mStatus;

			const IInstructionPtr findInstruction(int value) const;

	public:
			NeanderProcessor();

			virtual ~NeanderProcessor();

			virtual const MemoryPtr &getMemory() const override;

			virtual const AccumulatorPtr &getAccumulator() const override;

			virtual const ProgramCounterPtr &getProgramCounter() const override;

			virtual const Status &getStatus() const override;

			virtual void load(const MemoryPtr &memory) override;

			virtual void process() override;
	};
}

#endif //NEANDER_NEANDERPROCESSOR_H
