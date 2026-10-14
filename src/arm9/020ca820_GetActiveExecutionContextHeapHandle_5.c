/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
unsigned int GetActiveExecutionContextHeapHandle_5(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ca828: r0 = GetActiveExecutionContext();
L_20ca82c: r0 = ExecutionContext_GetHeapHandle(r0);
L_20ca838: return r0;
}
