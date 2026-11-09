#include "Main/Unknown/code_0210b708.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210b000.h"

void func_0210b734(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 firstWord = request->mSoundId;
    Vec3 *secondWord = request->mPositionSource;
    u32 result = func_0210bcf4(0x0u, firstWord, secondWord, handle, request);
}

void func_0210b708(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 firstWord = request->mSoundId;
    Vec3 *secondWord = request->mPositionSource;
    u32 result = func_0210bee8(0x0u, firstWord, secondWord, handle, request);
}
