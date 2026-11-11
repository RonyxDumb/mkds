#include "03/code_021c6708.h"
#include "03/code_021c209c.h"
#include "03/code_021c6764.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"

void UpdateEditInvalidMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateEditInvalidMessageClose);
    }
}

void UpdateEditInvalidMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        gEdit->mOamEntry->mAttr01 = gEdit->mOamEntry->mAttr01 & (0xc1fffcffu);
        SetUpdateFunction(UpdateEditFadeIn);
    }
}
