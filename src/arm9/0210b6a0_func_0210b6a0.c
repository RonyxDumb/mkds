/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0217ccb0 SDK_data_0217ccb0
#define data_0217ccbc SDK_data_0217ccbc
#define data_0217ccb4 SDK_data_0217ccb4
#define data_0217ccb8 SDK_data_0217ccb8
/* PURPOSE: Initializes four global fixed-point values.
 * This function computes two ratios from fixed constants, then clears two
 * related values. The exact gameplay role of these globals is uncertain.
 */

typedef int fx32;

extern fx32 FX_Div(fx32 numerator, fx32 denominator);

extern fx32 data_0217ccb0;
extern fx32 data_0217ccb4;
extern fx32 data_0217ccb8;
extern fx32 data_0217ccbc;

void func_0210b6a0(void)
{
    data_0217ccb0 = FX_Div(0x384000, 0x0afc8000);
    data_0217ccbc = FX_Div(0x1c2000, 0x0afc8000);
    data_0217ccb4 = 0;
    data_0217ccb8 = 0;
}
