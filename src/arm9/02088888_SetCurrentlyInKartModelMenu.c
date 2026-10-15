/* C reconstructed from original ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
void SetCurrentlyInKartModelMenu(int value)
{
    if (value)
        *(void **)0x0217af24 = (void *)0x02165fd4;
    else
        *(void **)0x0217af24 = (void *)0x02165fec;
}
