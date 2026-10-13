#pragma once
/* Function-specific inferred declarations. */
int SND_CountWaitingCommand(void);
void SoundInternal_RequestCommandProc(void);
void Sound_AllocateCommand(uint param_1);
uint Sound_AllocateCommandImpl(void);
uint Sound_CommandReceiveAndReply(uint param_1);
undefined4 Sound_FlushCommand(uint param_1);
bool Sound_IsCommandAvailable(void);

