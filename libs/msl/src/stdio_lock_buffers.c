#include "Main/System/runtime_locks_stdio_buffers.h"

u8 gStdinBuffer[0x100];
u8 gStdoutBuffer[0x100];
u8 gStderrBuffer[0x100];
u8 g_AnotherMutex[9][0x14];
u32 g_SomeCounter[9];
u32 g_SomeThreadId[9];
