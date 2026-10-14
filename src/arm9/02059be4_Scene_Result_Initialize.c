/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int InstanceStructN_from_thumb(unsigned int);
unsigned int Scene_Result_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2059bec: r0 = GetActiveExecutionContext();
L_2059bf0: r0 = ExecutionContext_GetHeapHandle(r0);
L_2059bf4: r0 = InstanceStructN_from_thumb(r0);
L_2059c00: return r0;
}
