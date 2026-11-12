#include "Main/Net/zero_word_received.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void SetZeroWordReceived(u32 *payload, int length) {
    if ((length == 4) && (*payload == 0)) {
        gConnectionWork->mZeroWordReceived = 1;
    }
}

#pragma thumb off
