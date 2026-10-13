/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int WriteSaveDataSection_FriendList_from_thumb(unsigned int);
extern unsigned int WriteSaveDataHeader_from_thumb(void);
unsigned int SaveFriendList(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205edd4: r0 = 0x217aa08u;
L_205edd8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_205eddc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 32));
L_205ede0: r0 = WriteSaveDataSection_FriendList_from_thumb(r0);
L_205ede4: r0 = WriteSaveDataHeader_from_thumb();
L_205edf0: return r0;
}
