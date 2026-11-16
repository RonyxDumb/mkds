#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_02109054.h"

void *it_emitSfx(SoundSource *source, u32 soundId) {
    SoundSource *sourceCopy = source;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 zero;
    u32 soundIdCompared;
    u32 skipId;
    soundIdCompared = soundIdCopy;
    skipId = 1u;
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
        return sourceCopy;
    }
    volume = 0x7fu;
    zero = 0u;
    return sfx_21090C4(sourceCopy, soundIdCopy, volume, zero);
}
