#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020f36d8.h"

void StartItemObjectSoundOnSource(ItemObject *item, s32 soundId) {
    SoundSource *sourceCopy = &item->mSoundSource;
    s32 soundIdCopy = soundId;
    u32 volume;
    u32 zero;
    s32 soundIdCompared;
    u32 skipId;
    soundIdCompared = soundIdCopy;
    skipId = 1u;
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
        return;
    }
    volume = 0x7fu;
    zero = 0u;
    StartSound(sourceCopy, soundIdCopy, volume, zero);
}
