/* C reconstructed from reference ARM instructions; full local bytes verified.
 * No whole-ROM or global ABI equivalence claim. */
struct WifiNibble {
    unsigned char value : 4;
    unsigned char rest : 4;
};

unsigned GetMaybeSomeWifiIdx(int i)
{
    return ((struct WifiNibble *)(
        *(unsigned *)0x0217d384 + i * 0x244 + 0x450))->value;
}
