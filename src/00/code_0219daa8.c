#include "00/code_0219daa8.h"
#include "00/code_0219d948.h"

u8 DWC_GetFriendStatus(void *friendData, char *statusString) {
    return DWC_GetFriendStatusSC(friendData, NULL, NULL, statusString);
}
