/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_Frame_ResetFromHead(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int Mem_Frame_ResetFromTail(unsigned int);
unsigned int Mem_ResetFrameHeap(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2018054: r4 = r1;
L_2018058: r5 = r0;
L_201805c: r1 = (r4&0x1u); cmp_a = r1; cmp_b = 0;
L_2018060: if ((cmp_a == cmp_b)) { goto L_2018068; }
L_2018064: r0 = Mem_Frame_ResetFromHead(r0,r1,r2,r3);
L_2018068: r0 = (r4&0x2u); cmp_a = r0; cmp_b = 0;
L_2018074: if ((cmp_a == cmp_b)) { return r0; }
L_2018078: r0 = r5;
L_201807c: r0 = Mem_Frame_ResetFromTail(r0);
L_2018088: return r0;
}
