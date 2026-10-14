/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_SendFifo48B SDK_data_0214c728
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G3_LoadMtx43(struct Mtx43 *mtx){
    reg_G3X_GXFIFO = 0x17;
    GX_SendFifo48B(mtx, (void *)&reg_G3X_GXFIFO);
}
