/*
 * ArraySlice.h
 *
 *  Created on: 04-12-2011
 *      Author: mvaldenegro
 */

#ifndef EPIC_CORE_ARRAYSLICE_H_
#define EPIC_CORE_ARRAYSLICE_H_

#include <epic.core/Core.h>

namespace Epic {
    namespace Core {

        template<typename T> class Array;

        template<typename T>
        class ArraySlice
        {
            friend class Array<T>;

            public:
                ~ArraySlice()
                {
                }

                T& operator[](size_t idx)
                {
                    EPIC_HARD_ASSERT(idx < length);

                    return targetArray->at(startIndex + idx);
                }

                const T& operator[](size_t idx) const
                {
                    return targetArray->at(startIndex + idx);
                }

            private:
                ArraySlice(Array<T> *target, size_t start, size_t end)
                : targetArray(target), startIndex(start), endIndex(end)
                {
                }

                Array<T> *targetArray;
                size_t startIndex;
                size_t endIndex;
                size_t length;
        };
    }
}

#endif /* EPIC_CORE_ARRAYSLICE_H_ */