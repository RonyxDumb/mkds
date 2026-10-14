/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CTRDGi_WriteAgbFlashSectorAsync SDK_data_0217b064
#define CTRDG_WriteAgbFlashSectorAsync func_0208c1d0
#include <nitro.h>

#pragma thumb off
void CTRDG_WriteAgbFlashSectorAsync (u16 secNo, u8 *src, CTRDG_TASK_FUNC callback)
{
	(*CTRDGi_WriteAgbFlashSectorAsync)(secNo, src, callback);
}
