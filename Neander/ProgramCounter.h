//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_PROGRAMCOUNTER_H
#define NEANDER_PROGRAMCOUNTER_H

#include <memory>

namespace Neander {

	class ProgramCounter {
	private:
			unsigned long mAddress;

	public:
			ProgramCounter();
			ProgramCounter(unsigned long address);

			unsigned long getAddress() const;
			void setAddress(unsigned long address);

			unsigned long incrementAddress();
	};

	typedef std::shared_ptr<ProgramCounter> ProgramCounterPtr;
}

#endif //NEANDER_PROGRAMCOUNTER_H
