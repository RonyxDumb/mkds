/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CTRDGi_EraseAgbFlashChipAsync SDK_data_0217b058
#define CTRDG_EraseAgbFlashChipAsync func_0208c218
#include <nitro.h>

#pragma thumb off
void CTRDG_EraseAgbFlashChipAsync (CTRDG_TASK_FUNC callback)
{
	(*CTRDGi_EraseAgbFlashChipAsync)(callback);
}
