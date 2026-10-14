/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_IsFinishedCommandTag func_020210c0
#define SND_RecvCommandReply Sound_CommandReceiveAndReply
#define RequestCommandProc SoundInternal_RequestCommandProc
#define SND_WaitForCommandProc func_02021154
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern BOOL SND_IsFinishedCommandTag(u32 tag);
extern const struct SNDCommand *SND_RecvCommandReply(u32 flags);
extern void RequestCommandProc(void);
void SND_WaitForCommandProc(u32 tag) {
    if (SND_IsFinishedCommandTag(tag))
        return;

    while (SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK) != NULL) { }

    if (SND_IsFinishedCommandTag(tag))
        return;

    RequestCommandProc();

    if (SND_IsFinishedCommandTag(tag))
        return;

    do {
        (void)SND_RecvCommandReply(SND_CMD_FLAG_BLOCK);
    } while (SND_IsFinishedCommandTag(tag) == 0);
}
