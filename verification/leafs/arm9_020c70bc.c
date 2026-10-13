
unsigned int IsSavingTimeTrialRecord(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c70bc: r0 = 0x217b3f4u;
L_20c70c0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c70c4: cmp_a = r0; cmp_b = 0x0u;
L_20c70c8: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 24)); }
L_20c70cc: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20c70d0: return r0;
}
