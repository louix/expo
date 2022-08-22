#pragma once

#include <shared_mutex>
#include "ABI47_0_0EXGLContext.h"

namespace ABI47_0_0expo {
namespace gl_cpp {

using ABI47_0_0EXGLContextWithLock = std::pair<ABI47_0_0EXGLContext *, std::shared_lock<std::shared_mutex>>;

UEXGLContextId ABI47_0_0EXGLContextCreate();
ABI47_0_0EXGLContextWithLock ABI47_0_0EXGLContextGet(UEXGLContextId id);
void ABI47_0_0EXGLContextDestroy(UEXGLContextId id);

} // namespace gl_cpp
} // namespace ABI47_0_0expo
