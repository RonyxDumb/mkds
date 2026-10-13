/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int StructMQRacerEntry_SomeFn_29(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210a644: r1 = 0x217c814u;
L_210a648: r2 = 0x210a724u;
L_210a64c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_210a650: *(unsigned int *)((unsigned char *)r0 + 1156) = (unsigned int)r1;
L_210a654: *(unsigned int *)((unsigned char *)r0 + 48) = (unsigned int)r2;
L_210a658: return r0;
}
