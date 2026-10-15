/* C reconstructed from reference ARM instructions; full local bytes verified.
 * No whole-ROM or global ABI equivalence claim. */

void Logo_StateHandler_CheckWiFiStatus_Second(void)
{
    if (*(unsigned *)0x02174e74 == 3) {
        volatile unsigned short *s =
            (volatile unsigned short *)(*(unsigned *)0x021a99e0 + 0x18);
        s[8] = 9;
        s[9] = 1;
    } else {
        volatile unsigned short *s =
            (volatile unsigned short *)(*(unsigned *)0x021a99e0 + 0x18);
        s[8] = 11;
        s[9] = 1;
    }
}
