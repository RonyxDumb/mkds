#include "Main/System/runtime_locks_stdio_buffers.h"

u8 gStdinBuffer[0x100];
u8 gStdoutBuffer[0x100];
u8 gStdioFile2Buffer[0x100];
u8 gLockMutexes[9][0x14];
u32 gLockHoldCounts[9];
u32 gLockOwnerThreadIds[9];
