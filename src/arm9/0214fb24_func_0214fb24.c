/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PMi_WriteRegister SDK_data_0214fd18
#define PM_SetAmpGain func_0214fb24
#include <nitro/spi/ARM9/pm.h>
#include <nitro/pxi.h>
#include <nitro/gx.h>
#include <nitro/spi/common/config.h>
#include <nitro/ctrdg.h>
#include <nitro/mb.h>
extern u32 PMi_WriteRegister (u16 registerAddr, u16 data);
#pragma thumb off
u32 PM_SetAmpGain (PMAmpGain status)
{
    return PMi_WriteRegister(REG_PMIC_PGA_GAIN_ADDR, (u16)status);
}
