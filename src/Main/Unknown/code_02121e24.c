#include "Main/Unknown/code_02121e24.h"
#include "00/code_021832d8.h"

u32 GetWiFiSessionCharacterIndex(u32 index) {
    return gWiFiSession->mIndexMessages[index].mCharacterIndex;
}

u32 GetWiFiSessionKartIndex(u32 index) {
    return gWiFiSession->mIndexMessages[index].mKartIndex;
}

u32 GetWiFiSessionPickedCourseId(u32 index) {
    return gWiFiSession->mIndexMessages[index].mPickedCourseId;
}
