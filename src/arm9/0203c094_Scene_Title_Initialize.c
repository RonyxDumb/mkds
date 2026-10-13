/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int SomeVramConfig(void);
extern unsigned int LoadTitleFiles_from_thumb(void);
extern unsigned int MaybeResetInput(void);
unsigned int Scene_Title_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203c09c: r0 = GetActiveExecutionContext();
L_203c0a0: r0 = ExecutionContext_GetHeapHandle(r0);
L_203c0a4: r0 = SomeVramConfig();
L_203c0a8: r0 = LoadTitleFiles_from_thumb();
L_203c0ac: r0 = MaybeResetInput();
L_203c0b8: return r0;
}
