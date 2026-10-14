/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisposeLoadedOverlay(void);
extern unsigned int UpdateOverlayStatusWithKind(unsigned int);
extern unsigned int WaitOverlayLoadedStarted(void);
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int func_0202f2b4(unsigned int);
unsigned int Scene_WLMenu_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_204b044: r0 = 0x21759d0u;
L_204b048: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_204b04c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 32));
L_204b050: cmp_a = r0; cmp_b = 0x3u;
L_204b054: if ((cmp_a != cmp_b)) { goto L_204b068; }
L_204b058: r0 = DisposeLoadedOverlay();
L_204b05c: r0 = 0x0u;
L_204b060: r0 = UpdateOverlayStatusWithKind(r0);
L_204b064: r0 = WaitOverlayLoadedStarted();
L_204b068: r0 = GetActiveExecutionContext();
L_204b06c: r0 = ExecutionContext_GetHeapHandle(r0);
L_204b070: r0 = func_0202f2b4(r0);
L_204b07c: return r0;
}
