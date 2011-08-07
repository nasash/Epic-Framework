/*
 * File:   R8Image.h
 * Author: mvaldenegro
 *
 * Created on 7 de agosto de 2011, 04:17 PM
 */

#ifndef EPIC_IMAGE_R8IMAGE_H
#define	EPIC_IMAGE_R8IMAGE_H

#include <epic.image/Image.h>

namespace Epic {
    namespace Image {
        class R8Image : public Image
        {
            public:
                R8Image(size_t width, size_t height);
                ~R8Image();

                size_t bytesPerPixel() const;
                Pixel pixel(size_t row, size_t column) const;
                void setPixel(size_t row, size_t column, const Pixel& pixel);
        };
    }
}
#endif	/* R8IMAGE_H */

