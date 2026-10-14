/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_Copy32B SDK_data_0214d0e0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G3X_SetFogTable(void *tbl_ptr){
    MI_Copy32B(tbl_ptr, (void *)&reg_G3X_FOG_TABLE_0);
}
