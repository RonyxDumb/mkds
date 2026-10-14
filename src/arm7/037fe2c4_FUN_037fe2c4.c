/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ReleaseTrackChannelAll FUN_037fe40c
#define FreeTrackChannelAll FUN_037fe3d0
#define CloseTrack FUN_037fe2c4
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern void ReleaseTrackChannelAll(SNDTrack *track_p, SNDPlayer *player_p, int release);
extern void FreeTrackChannelAll(SNDTrack *track_p);
#pragma thumb off
void CloseTrack(SNDTrack *track_p, SNDPlayer *player_p)
{
    ReleaseTrackChannelAll(track_p, player_p, -1);
    FreeTrackChannelAll(track_p);
}
