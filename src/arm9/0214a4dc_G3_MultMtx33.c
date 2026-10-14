/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_Copy36B SDK_data_0214d0fc
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G3_MultMtx33(struct Mtx33 *mtx){
    reg_G3X_GXFIFO = 0x1A;
    MI_Copy36B(mtx, (void *)&reg_G3X_GXFIFO);
}
