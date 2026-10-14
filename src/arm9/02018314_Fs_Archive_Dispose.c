/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_SndArcStrmPrepare Fs_Archive_UnloadFatFnt
#define NNS_SndArcStrmStartPrepared Fs_UnregisterArchive
#define NNS_SndArcStrmStart Fs_Archive_Dispose

#include <nnsys/snd/sndarc_stream.h>

#include <nnsys/misc.h>
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/stream.h>
#include <nnsys/snd/fader.h>
#include <nnsys/snd/config.h>
extern BOOL NNS_SndArcStrmPrepare (struct NNSSndStrmHandle * handle, int strmNo, u32 offset);
extern void NNS_SndArcStrmStartPrepared (NNSSndStrmHandle * handle);
#pragma thumb off
BOOL NNS_SndArcStrmStart (NNSSndStrmHandle * handle, int strmNo, u32 offset)
{
    BOOL result;

    NNS_NULL_ASSERT(handle);

    result = NNS_SndArcStrmPrepare(handle, strmNo, offset);
    if (!result) return FALSE;

    NNS_SndArcStrmStartPrepared(handle);

    return TRUE;
}
