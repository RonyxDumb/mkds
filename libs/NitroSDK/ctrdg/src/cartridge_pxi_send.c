#include "cartridge_pxi_send.h"
#include "arm_fifo_messaging.h"
#include "bios_calls.h"

#pragma thumb on

// Sends data on FIFO tag 13, waiting and trying again until the send is accepted.
void CTRDGi_SendtoPxi(u32 data) {
    if (PXI_SendWordByFifo(13, data, 0) != 0) {
        do {
            WaitByLoop(1);
        } while (PXI_SendWordByFifo(13, data, 0) != 0);
    }
}
