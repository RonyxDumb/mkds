#include "03/code_021c9cb0.h"
#include "03/code_021c209c.h"
#include "03/code_021c9cf4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"

void UpdateExchangeKeyMessageResult(void) {
    int messageAnswer;
    messageAnswer = func_ov003_021cef80();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        SetUpdateFunction(UpdateExchangeKeyMessageClose);
    }
}

void UpdateExchangeKeyMessageClose(void) {
    int messageOpen;
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        SetUpdateFunction(StartExchangeKeyClose);
    }
}
