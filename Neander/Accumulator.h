//
// Created by Pietro Caselani on 11/13/15.
//

#ifndef NEANDER_ACCUMULATOR_H
#define NEANDER_ACCUMULATOR_H

#include <memory>

namespace Neander {

	class Accumulator {
	private:
			unsigned long mValue;

	public:
			Accumulator();
			Accumulator(unsigned long value);

			unsigned long getValue() const;
			void setValue(unsigned long value);
	};

	typedef std::shared_ptr<Accumulator> AccumulatorPtr;
}

#endif //NEANDER_ACCUMULATOR_H
