#include "Main/Unknown/code_0210bad4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109000.h"

void MapStartSoundWhileRequestedFullVolume(void *soundSource, int soundId) {
    StartSoundWhileRequested(soundSource, soundId, 0x7f, 0);
}
