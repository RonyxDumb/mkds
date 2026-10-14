/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_PrepareSeq FUN_037fed60
#define SND_StartPreparedSeq FUN_037fed40
#define SND_StartSeq FUN_037fed24
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank_p);
extern void SND_StartPreparedSeq(int playerNo);
#pragma thumb off
void SND_StartSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank_p)
{
    SND_PrepareSeq(playerNo, seqBase, seqOffset, bank_p);
    SND_StartPreparedSeq(playerNo);
}
