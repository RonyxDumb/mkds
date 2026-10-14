/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_020553c0 GXi_NopClearFifo128_
#define func_02055780 G3X_ClearFifo
extern void func_020553c0(unsigned addr);
void func_02055780(void)
{
    func_020553c0(0x4000400);
    while (*(volatile unsigned *)0x4000600 & 0x8000000)
        ;
}
