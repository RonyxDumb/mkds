/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_GetSizeOfX_ SDK_data_02148cd0
#define GX_GetSizeOfOBJ func_02148cb8
#include <nitro/gx/gx_vramcnt.h>
#include <nitro/hw/ARM9/ioreg_G3X.h>
#include <nitro/hw/ARM9/ioreg_GX.h>
#include <nitro/hw/ARM9/ioreg_GXS.h>

#include "gxstate.h"
    #include <nitro/code32.h>
#include <nitro/codereset.h>
    #include <nitro/code32.h>
    #include <nitro/codereset.h>
extern u32 GX_GetSizeOfX_ (u32 bit);
#pragma thumb off
u32 GX_GetSizeOfOBJ (void)
{
	return GX_GetSizeOfX_(gGXState.vramCnt.obj);
}
