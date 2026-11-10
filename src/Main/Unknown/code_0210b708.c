#include "Main/Unknown/code_0210b708.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210b000.h"

void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 soundId = request->mSoundId;
    Vec3 *positionSource = request->mPositionSource;
    u32 result = StartOrUpdateSndHandleSound(0x0u, soundId, positionSource, handle, request);
}

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 soundId = request->mSoundId;
    Vec3 *positionSource = request->mPositionSource;
    u32 result = StartOrUpdateSndHandleSoundInMode2(0x0u, soundId, positionSource, handle, request);
}
