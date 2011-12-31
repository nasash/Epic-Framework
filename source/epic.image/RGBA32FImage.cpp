/*
 * Copyright (C) 2011 Matias Valdenegro <matias.valdenegro@gmail.com>
 * This file is part of Epic Framework.
 *
 * Epic Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Epic Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Epic Framework.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "RGBA32FImage.h"

namespace Epic {
    namespace Image {

        RGBA32FImage::RGBA32FImage(size_t width, size_t height)
        : FloatImage(width, height, 4, FloatPixelFormat::RGBA32F)
        {
        }

        RGBA32FImage::~RGBA32FImage()
        {
        }

        PixelF RGBA32FImage::pixel(size_t row, size_t column) const
        {
            const float *data = pixelData();
            size_t idx = index(row, column);

            return PixelF(data[idx], data[idx + 1], data[idx + 2], data[idx + 3]);
        }

        void RGBA32FImage::setPixel(size_t row, size_t column, const PixelF& pixel)
        {
            setPixel(row, column, pixel.r, pixel.g, pixel.b, pixel.a);
        }

        void RGBA32FImage::setPixel(size_t row, size_t column, float r, float g, float b, float a)
        {
            float *data = pixelData();
            size_t idx = index(row, column);

            data[idx    ] = r;
            data[idx + 1] = g;
            data[idx + 2] = b;
            data[idx + 3] = a;
        }


    } /* namespace Image */
} /* namespace Epic */
