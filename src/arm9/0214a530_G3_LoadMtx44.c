/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_SendFifo64B SDK_data_0214c74c
#include <nitro/gx/g3imm.h>
#include <nitro/mi/dma.h>
#include "../include/gxasm.h"

#pragma thumb off
void G3_LoadMtx44 (const MtxFx44 *m)
{
	SDK_NULL_ASSERT(m);

	reg_G3X_GXFIFO = G3OP_MTX_LOAD_4x4;
	GX_SendFifo64B(&m->_00, (void *)&reg_G3X_GXFIFO);
}
