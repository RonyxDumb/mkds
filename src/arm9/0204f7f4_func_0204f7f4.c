/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_IrqCallback SDK_data_0214f680
#define OSi_IrqDma0 func_0204f7f4
#include "sections.h"
#include "OS_irqTable.h"
#include "code32.h"
extern void OSi_IrqCallback(s32 index);
void OSi_IrqDma0(void)
{
    OSi_IrqCallback(0);
}
