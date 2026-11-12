#include "Main/Net/packed_index.h"
#include "00/code_021832d8.h"

s32 GetPackedIndex(s32 index) {
    return gWiFiSession->mPackedIndices[index];
}

s32 GetIndexOfPackedIndex(u8 packedIndex) {
    s8 slotIndex;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        if (packedIndex == gWiFiSession->mPackedIndices[slotIndex]) {
            return slotIndex;
        }
    }
    return -1;
}
