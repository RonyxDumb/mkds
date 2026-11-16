#include "sound_bank_wave_archive.h"
#include "arena_cache_init.h"
#include "thread_scheduler.h"
#include "sound_init_and_mutex.h"

void SND_AssignWaveArc(SNDBankData *bank, s32 index, SNDWaveArc *waveArc) {
    SNDWaveArc *oldArc;
    SNDWaveArcLink *cur;
    SNDWaveArcLink *link;
    SNDWaveArcLink *top;
    SNDWaveArcLink *next;

    Sound_LockMutex();
    oldArc = bank->mWaveArcLink[index].mWaveArc;
    if (oldArc != 0) {
        if (waveArc == oldArc) {
            Sound_UnlockMutex();
            return;
        }
        cur = oldArc->mTopLink;
        link = &bank->mWaveArcLink[index];
        if (link == cur) {
            oldArc->mTopLink = bank->mWaveArcLink[index].mNext;
            DC_SomeClean(bank->mWaveArcLink[index].mWaveArc, 0x3c);
        } else {
            while (cur != 0) {
                next = cur->mNext;
                if (link == next) {
                    break;
                }
                cur = next;
            }
            cur->mNext = bank->mWaveArcLink[index].mNext;
            DC_SomeClean(cur, 8);
        }
    }
    top = waveArc->mTopLink;
    waveArc->mTopLink = &bank->mWaveArcLink[index];
    bank->mWaveArcLink[index].mNext = top;
    bank->mWaveArcLink[index].mWaveArc = waveArc;
    Sound_UnlockMutex();
    DC_SomeClean(bank, 0x3c);
    DC_SomeClean(waveArc, 0x3c);
}

// Takes each of the four entries of bank out of the list of the wave archive it is in.
void SND_DestroyBank(SNDBankData *bank) {
    s32 linkIndex;
    SNDWaveArc *waveArchive;
    SNDWaveArcLink *cur;
    SNDWaveArcLink *link;
    SNDWaveArcLink *next;

    Sound_LockMutex();
    link = &bank->mWaveArcLink[0];
    for (linkIndex = 0; linkIndex < 4; linkIndex++) {
        waveArchive = bank->mWaveArcLink[linkIndex].mWaveArc;
        if (waveArchive != 0) {
            cur = waveArchive->mTopLink;
            if (link == cur) {
                waveArchive->mTopLink = bank->mWaveArcLink[linkIndex].mNext;
                DC_SomeClean(waveArchive, 0x3c);
            } else {
                while (cur != 0) {
                    next = cur->mNext;
                    if (link == next) {
                        break;
                    }
                    cur = next;
                }
                cur->mNext = bank->mWaveArcLink[linkIndex].mNext;
                DC_SomeClean(cur, 8);
            }
        }
        link++;
    }
    Sound_UnlockMutex();
}

// Clears every entry in the list of waveArc.
void SND_DestroyWaveArc(SNDWaveArc *waveArc) {
    SNDWaveArcLink *cur;
    SNDWaveArcLink *next;

    Sound_LockMutex();
    cur = waveArc->mTopLink;
    if (cur != 0) {
        do {
            next = cur->mNext;
            cur->mWaveArc = 0;
            cur->mNext = 0;
            DC_SomeClean(cur, 8);
            cur = next;
        } while (next != 0);
    }
    Sound_UnlockMutex();
}

// Sets pos to the start of the instrument entries.
void SND_GetFirstInstDataPos(SNDInstPos *pos) {
    SNDInstPos first;

    first.mPrgNo = 0;
    first.mIndex = 0;
    *pos = first;
}

// Copies the instrument entry at pos into inst and moves pos on; returns 0 when there are no more.
u32 SND_GetNextInstData(SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos) {
    u32 entry;
    InstSimple *simple;
    InstDrumSet *drumTable;
    InstKeySplit *keyTable;

    while (pos->mPrgNo < bank->mInstCount) {
        entry = bank->mInstOffset[pos->mPrgNo];
        inst->mType = entry;
        switch (inst->mType) {
            case INSTRUMENT_TYPE_PCM:
            case INSTRUMENT_TYPE_PSG:
            case INSTRUMENT_TYPE_NOISE:
            case INSTRUMENT_TYPE_DIRECT_PCM:
            case INSTRUMENT_TYPE_EMPTY:
                simple = OFFSET_PTR(InstSimple, bank, (entry >> 8));
                inst->mWave = simple->mWave;
                inst->mKeyAndEnvelope = simple->mKeyAndEnvelope;
                inst->mReleaseAndPan = simple->mReleaseAndPan;
                pos->mPrgNo++;
                return 1;
            case INSTRUMENT_TYPE_DRUM_SET:
                drumTable = OFFSET_PTR(InstDrumSet, bank, (entry >> 8));
                while (pos->mIndex < drumTable->mMax - drumTable->mMin + 1) {
                    *inst = drumTable->mInstOffset[pos->mIndex];
                    pos->mIndex++;
                    return 1;
                }
                break;
            case INSTRUMENT_TYPE_KEY_SPLIT:
                keyTable = OFFSET_PTR(InstKeySplit, bank, (entry >> 8));
                while (pos->mIndex < KEY_SPLIT_ENTRY_COUNT) {
                    if (keyTable->mKey[pos->mIndex] == 0) {
                        break;
                    }
                    *inst = keyTable->mInstOffset[pos->mIndex];
                    pos->mIndex++;
                    return 1;
                }
                break;
        }
        pos->mPrgNo++;
        pos->mIndex = 0;
    }
    return 0;
}

// Returns the number of wave data entries of waveArc.
u32 SND_GetWaveDataCount(SNDWaveArc *waveArc) {
    return waveArc->mWaveCount;
}

void SND_SetWaveDataAddress(SNDWaveArc *waveArc, u32 index, void *address) {
    Sound_LockMutex();
    waveArc->mWaveOffset[index] = (u32) address;
    DC_SomeClean(&waveArc->mWaveOffset[index], 4);
    Sound_UnlockMutex();
}
