#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"

void mobj_driverEmitSfx2(void *soundSource, u32 soundId) {
    u32 value0 = (u32) soundSource;
    u32 soundIdCopy = soundId;
    u32 unused;
    value0 = (u32) driver_emitSfx2((SoundSource *) value0, soundIdCopy);
}

void mobj_driverEmitSfx(void *soundSource, u32 soundId) {
    u32 soundSourceCopy = (u32) soundSource;
    u32 soundIdCopy = soundId;
    u32 unused;
    driver_emitSfx(soundSourceCopy, soundIdCopy);
}
