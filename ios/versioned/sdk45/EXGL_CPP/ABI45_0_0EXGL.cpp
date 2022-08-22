#include "UEXGL.h"
#include "ABI45_0_0EXGLContext.h"
#include "ABI45_0_0EXGLContextManager.h"

using namespace ABI45_0_0expo::gl_cpp;

UEXGLContextId UEXGLContextCreate() {
  return ABI45_0_0EXGLContextCreate();
}

#ifdef __APPLE__
void UEXGLContextPrepare(void *jsiPtr, UEXGLContextId exglCtxId, UEXGLFlushMethodBlock flushMethod) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->prepareContext(*reinterpret_cast<jsi::Runtime *>(jsiPtr), [flushMethod] { flushMethod(); });
  }
}
#else
void UEXGLContextPrepare(void *jsiPtr, UEXGLContextId exglCtxId, std::function<void(void)> flushMethod) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->prepareContext(*reinterpret_cast<jsi::Runtime *>(jsiPtr), flushMethod);
  }
}
#endif

bool UEXGLContextNeedsRedraw(UEXGLContextId exglCtxId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    return exglCtx->needsRedraw;
  }
  return false;
}

void UEXGLContextDrawEnded(UEXGLContextId exglCtxId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->needsRedraw = false;
  }
}

void UEXGLContextDestroy(UEXGLContextId exglCtxId) {
  ABI45_0_0EXGLContextDestroy(exglCtxId);
}

void UEXGLContextFlush(UEXGLContextId exglCtxId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->flush();
  }
}

void UEXGLContextSetDefaultFramebuffer(UEXGLContextId exglCtxId, GLint framebuffer) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->defaultFramebuffer = framebuffer;
  }
}

UEXGLObjectId UEXGLContextCreateObject(UEXGLContextId exglCtxId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    return exglCtx->createObject();
  }
  return 0;
}

void UEXGLContextDestroyObject(UEXGLContextId exglCtxId, UEXGLObjectId exglObjId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->destroyObject(exglObjId);
  }
}

void UEXGLContextMapObject(UEXGLContextId exglCtxId, UEXGLObjectId exglObjId, GLuint glObj) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    exglCtx->mapObject(exglObjId, glObj);
  }
}

GLuint UEXGLContextGetObject(UEXGLContextId exglCtxId, UEXGLObjectId exglObjId) {
  auto [exglCtx, lock] = ABI45_0_0EXGLContextGet(exglCtxId);
  if (exglCtx) {
    return exglCtx->lookupObject(exglObjId);
  }
  return 0;
}
