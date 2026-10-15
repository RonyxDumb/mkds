/* C reconstructed from original ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
extern int TextSystem_WasAnyDialogButtonPressed_from_thumb(void);
extern void TextSystem_CloseDialog_from_thumb(void);
extern int TextSystem_IsDialogFinished_from_thumb(void);
extern int TextSystem_IsButton2Focused_from_thumb(void);

void Logo_StateHandler_AskEraseSaveData_Second(void)
{
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb()) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (!TextSystem_IsDialogFinished_from_thumb())
        return;
    if (!TextSystem_IsButton2Focused_from_thumb()) {
        short *state = (short *)(*(char **)0x021a99e0 + 0x18);
        state[8] = 6;
        state[9] = 1;
    } else {
        short *state = (short *)(*(char **)0x021a99e0 + 0x18);
        state[8] = 8;
        state[9] = 1;
    }
}
