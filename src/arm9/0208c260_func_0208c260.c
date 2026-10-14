/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CTRDGi_EraseAgbFlashSectorAsync SDK_data_0217b05c
#define CTRDG_EraseAgbFlashSectorAsync func_0208c260
#include <nitro.h>

#pragma thumb off
void CTRDG_EraseAgbFlashSectorAsync (u16 secNo, CTRDG_TASK_FUNC callback)
{
	(*CTRDGi_EraseAgbFlashSectorAsync)(secNo, callback);
}
