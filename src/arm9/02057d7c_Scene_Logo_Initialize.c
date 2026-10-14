/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int InitializeLogoContext(unsigned int);
unsigned int Scene_Logo_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2057d84: r0 = GetActiveExecutionContext();
L_2057d88: r0 = ExecutionContext_GetHeapHandle(r0);
L_2057d8c: r0 = InitializeLogoContext(r0);
L_2057d98: return r0;
}
