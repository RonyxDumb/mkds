#include "Main/Unknown/code_0210d9a0.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

// Switches to sound mode b (0 to 5): 0, 1, 3 and 4 stop the sounds, 5 fades them out and keeps the old mode, 1 and 2
// fade back in from 5.
void SetSoundMode(SoundModeHolder *modeHolder, u32 newMode) {
    u32 fadeSteps;

    fadeSteps = sound_getFadeFrameCount();
    switch (newMode) {
        case 0:
            if (modeHolder->mMode != 0) {
                sfx_stopAll(0);
                sfx_stopAllSfxStandalone(0);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->field10, 0);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->fieldC, 0);
                if (modeHolder->field18 != NULL) {
                    NNS_SndPlayerStopSeq(modeHolder->field18, 0);
                }
                modeHolder->field10 = 0;
                modeHolder->fieldC = 0;
            }
            break;
        case 1:
            if (modeHolder->mMode != 1) {
                sfx_stopAll(0);
                sfx_stopAllSfxStandalone(0);
                if (modeHolder->mMode == 5) {
                    fadeSteps = sound_getFadeFrameCount();
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->fieldC, 0x7f, fadeSteps);
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->field10, 0x7f, fadeSteps);
                    if (modeHolder->field18 != NULL) {
                        NNS_SndPlayerMoveVolume(modeHolder->field18, 0x7f, fadeSteps);
                    }
                }
                modeHolder->field10 = 0;
                modeHolder->fieldC = 1;
            }
            break;
        case 2:
            if (modeHolder->mMode != 2) {
                if (modeHolder->mMode == 5) {
                    u32 fadeStepsNow;

                    fadeStepsNow = sound_getFadeFrameCount();
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->fieldC, 0x7f, fadeStepsNow);
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->field10, 0x7f, fadeStepsNow);
                    if (modeHolder->field18 != NULL) {
                        NNS_SndPlayerMoveVolume(modeHolder->field18, 0x7f, fadeStepsNow);
                    }
                    sfx_moveVolume(0x7f, fadeSteps);
                }
                modeHolder->field10 = 1;
                modeHolder->fieldC = 1;
            }
            break;
        case 3:
            if (modeHolder->mMode != 3) {
                modeHolder->field10 = 0;
                modeHolder->fieldC = 0;
                sfx_stopAll(5);
                sfx_stopAllSfxStandalone(5);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->field10, 5);
            }
            break;
        case 4:
            if (modeHolder->mMode != 4) {
                modeHolder->field10 = 0;
                modeHolder->fieldC = 0;
                sfx_stopAll(fadeSteps);
                sfx_stopAllSfxStandalone(fadeSteps);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->field10, fadeSteps);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->fieldC, fadeSteps);
                if (modeHolder->field18 != NULL) {
                    NNS_SndPlayerStopSeq(modeHolder->field18, fadeSteps);
                }
            }
            break;
        case 5:
            if (modeHolder->mMode != 5) {
                NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->fieldC, 0, fadeSteps);
                NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->field10, 0, fadeSteps);
                if (modeHolder->field18 != NULL) {
                    NNS_SndPlayerMoveVolume(modeHolder->field18, 0, fadeSteps);
                }
                modeHolder->field10 = 0;
                modeHolder->fieldC = 0;
                sfx_moveVolume(0, fadeSteps);
                modeHolder->mSavedMode = modeHolder->mMode;
            }
            break;
    }
    modeHolder->mMode = newMode;
}
