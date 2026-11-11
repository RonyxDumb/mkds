#include "Main/Unknown/code_021529e0.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on
void SetFriendDataType(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 value;
    flags = GetFriendDataFlags(friendData);
    value = 3;
    flags = flags & ~value;
    value = flags;
    value = value | dataType;
    SetFriendDataFlags(friendData, value);
}
#pragma thumb off
