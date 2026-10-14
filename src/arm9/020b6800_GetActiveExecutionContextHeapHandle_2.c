/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
unsigned int GetActiveExecutionContextHeapHandle_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20b6808: r0 = GetActiveExecutionContext();
L_20b680c: r0 = ExecutionContext_GetHeapHandle(r0);
L_20b6818: return r0;
}
