//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_MEMORY_H
#define NEANDER_MEMORY_H

#include <vector>
#include "IInstruction.h"

using namespace std;

namespace Neander {

	class IInstruction;

	typedef shared_ptr<IInstruction> IInstructionPtr;

	typedef vector<unsigned long> Addresses;
	typedef shared_ptr<Addresses> AddressesPtr;

	class Memory {
	private:
			AddressesPtr mAddresses;

			unsigned long mTotal, mInnerPosition;

			const void checkPosition(unsigned long position) const;

	public:
			Memory();

			const AddressesPtr &getAddresses() const;

			unsigned long getTotal() const;

			void setTotal(unsigned long total);

			unsigned long getMinPosition() const;

			unsigned long getMaxPosition() const;

			const void addInstruction(IInstructionPtr instruction);

			const void addInstruction(unsigned long memoryPosition, IInstructionPtr instruction);

			const void addValue(unsigned long value);

			const bool isPositionValid(unsigned long position) const;

			const bool isNegativeValue(unsigned long value) const;

			const unsigned long getValue(unsigned long position) const;

			const void addValue(unsigned long position, unsigned long value);

			const unsigned long size() const;
	};

	template <class T>
	static shared_ptr<IInstruction> makeInstruction() {
		return static_pointer_cast<IInstruction>(make_shared<T>());
	}
}

#endif //NEANDER_MEMORY_H
