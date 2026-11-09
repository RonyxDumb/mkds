#include "Main/Unknown/code_020ca69c.h"

#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ca6b8.h"

#pragma thumb on
void ClearEmblemChoisesPointer(void) {
    gEmblemChoises = NULL;
}
#pragma thumb off

#pragma thumb on
void RequestEmblemChoisesGraphicsUpload(void) {
    gEmblemChoises->mGraphicsUploadRequested = TRUE;
}
#pragma thumb off

#pragma thumb on

u32 GetEmblemChoisesResult(void) {
    return (gEmblemChoises->mResult);
}

#pragma thumb off
