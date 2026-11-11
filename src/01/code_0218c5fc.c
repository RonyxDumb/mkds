#include "01/code_0218c5fc.h"
#include "01/code_02188e24.h"
#include "01/code_0218c61c.h"

void SetKurikingSoundCallbacks(Unk02188950 *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0x20, KurikingFirstSoundCallback, 0x40, KurikingSecondSoundCallback);
}
