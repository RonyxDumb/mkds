/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ctrdgi_task_work SDK_data_0217b4e4
#define CTRDGi_IsTaskAvailable func_020d3e18
#include <nitro.h>
extern CTRDGiTaskWork *ctrdgi_task_work;
#pragma thumb off
BOOL CTRDGi_IsTaskAvailable (void)
{
	return (ctrdgi_task_work != NULL);
}
