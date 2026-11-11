#include "01/code_0218b278.h"
#include "01/code_0218b298.h"

void SetBombKingSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 1, BombKingFirstSoundCallback, 0x1f, BombKingSecondSoundCallback);
}
