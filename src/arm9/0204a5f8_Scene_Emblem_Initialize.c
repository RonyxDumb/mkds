/* C reconstructed from reference ARM instructions; full local bytes verified.
 * No whole-ROM or global ABI equivalence claim. */
extern void *GetActiveExecutionContext(void);
extern void *ExecutionContext_GetHeapHandle(void *);
extern void MaybeInitializeSomeWirelessShit(void *);
extern void MaybeResetInput(void);
extern void Menu_EmblemOverlayInitialize(void);

void Scene_Emblem_Initialize(void)
{
    MaybeInitializeSomeWirelessShit(
        ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    MaybeResetInput();
    Menu_EmblemOverlayInitialize();
}
