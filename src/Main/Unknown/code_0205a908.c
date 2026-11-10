#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0205a92c.h"

void UpdateItemDataSlots(void) {
    ExpireItemDataSlots();
    WriteItemDataSlotsToSendBuffer();
    StoreReceivedItemDataSlots();
    ProcessOtherParticipantItemData();
}
