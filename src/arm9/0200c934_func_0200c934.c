/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_IrqCallback SDK_data_0200c994
#define OSi_IrqTimer1 func_0200c934
#include "sections.h"
#include "OS_irqTable.h"
#include "code32.h"
extern void OSi_IrqCallback(s32 index);
void OSi_IrqTimer1(void)
{
    OSi_IrqCallback(5);
}
