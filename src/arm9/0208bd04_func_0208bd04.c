/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_020a0ea0 SDK_data_0217b040
#define _ZN4Heap8AllocateEj SDK_data_02036bec
#define func_0203cc0c func_0208bd04
/* func_0203cc0c at 0x0203cc0c -- allocates from the default heap via
 * Heap::Allocate(unsigned) (mangled names referenced directly from C). */

extern void* data_020a0ea0;
extern void* _ZN4Heap8AllocateEj(void* heap, unsigned int size);

void* func_0203cc0c(unsigned int size)
{
    return _ZN4Heap8AllocateEj(data_020a0ea0, size);
}
