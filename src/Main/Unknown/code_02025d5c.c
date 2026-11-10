#include "Main/Unknown/code_02025d5c.h"

#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 GetKartMessageIndex(u32 kartIndex) {
    return gKartMessageIndexTable[kartIndex];
}
#pragma thumb off

#pragma thumb on
u32 GetCourseMessageIndex(u32 courseId) {
    return gCourseMessageIndexTable[courseId];
}
#pragma thumb off

#pragma thumb on

int GetGhostCourseMessageIndex(int courseId) {
    int messageIndex;
    messageIndex = gCourseMessageIndexTable[courseId];
    if (messageIndex != -1) {
        messageIndex = messageIndex + -0x1a;
    }
    return messageIndex;
}

int GetWiFiCourseMessageIndex(int courseId) {
    int messageIndex;
    messageIndex = gCourseMessageIndexTable[courseId];
    if (messageIndex != -1) {
        messageIndex = messageIndex + 4;
    }
    return messageIndex;
}

#pragma thumb off
