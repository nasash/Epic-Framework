/*
 * File:   CLContext.h
 * Author: mvaldenegro
 *
 * Created on 13 de marzo de 2011, 07:44 PM
 */

#ifndef EPIC_OPENCL_CLCONTEXT_H
#define	EPIC_OPENCL_CLCONTEXT_H

#include <epic.core/Array.h>

#include <epic.bindings.opencl/Device.h>
#include <epic.bindings.opencl/CommandQueue.h>
#include <epic.bindings.opencl/Program.h>
#include <epic.bindings.opencl/Platform.h>
#include <epic.bindings.opencl/Buffer.h>
#include <epic.bindings.opencl/Image2D.h>
#include <epic.bindings.opencl/Image3D.h>
#include <epic.bindings.opencl/ImageFormat.h>

#include <CL/opencl.h>

namespace Epic {
    namespace OpenCL {
        class Context
        {
            public:
                Context(const Platform& platform, cl_device_type deviceType);
                Context(const Platform& platform, const Epic::Core::Array<Device>& devices);
                Context(const Context& other);
                ~Context();

                inline cl_context contextHandle() const
                {
                    return mContext;
                }

                Epic::Core::Array<Device> devices() const;

                size_t getInfoSize(cl_context_info paramName) const;
                void getInfo(cl_context_info paramName, size_t paramValueSize, void *paramValue) const;

                CommandQueue createCommandQueue(const Device& device, cl_command_queue_properties properties = 0) const;
                
                Buffer createBuffer(cl_mem_flags flags, size_t size, void *hostPointer = nullptr) const;
                
                Image2D createImage2D(cl_mem_flags flags, const ImageFormat& format,
                                      size_t width, size_t height, size_t rowPitch = 0,
                                      void *hostPointer = nullptr);
                
                Image3D createImage3D(cl_mem_flags flags, const ImageFormat& format,
                                      size_t width, size_t height, size_t depth,
                                      size_t rowPitch = 0, size_t slicePitch = 0,
                                      void *hostPointer = nullptr);
                
                //Buffer createImage3D();
                //Sampler clCreateSampler();
                Program createProgram(const Epic::Core::ASCIIString& sourceCode) const;

            private:
                cl_context mContext;
        };
    }
}

#endif	/* EPIC_OPENCL_CLCONTEXT_H */

