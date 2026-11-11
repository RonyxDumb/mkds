#include "03/code_021c9cb0.h"
#include "03/code_021c209c.h"
#include "03/code_021c9cf4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"

void UpdateExchangeKeyMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateExchangeKeyMessageClose);
    }
}

void UpdateExchangeKeyMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartExchangeKeyClose);
    }
}
