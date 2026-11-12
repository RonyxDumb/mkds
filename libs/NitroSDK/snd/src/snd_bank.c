#include "snd_bank.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "snd_main.h"

void SND_AssignWaveArc(SNDBankData *bank, s32 index, SNDWaveArc *waveArc) {
    SNDWaveArc *oldArc;
    SNDWaveArcLink *cur;
    SNDWaveArcLink *link;
    SNDWaveArcLink *top;
    SNDWaveArcLink *next;

    SNDi_LockMutex();
    oldArc = bank->mWaveArcLink[index].mWaveArc;
    if (oldArc != 0) {
        if (waveArc == oldArc) {
            SNDi_UnlockMutex();
            return;
        }
        cur = oldArc->mTopLink;
        link = &bank->mWaveArcLink[index];
        if (link == cur) {
            oldArc->mTopLink = bank->mWaveArcLink[index].mNext;
            DC_StoreRange(bank->mWaveArcLink[index].mWaveArc, 0x3c);
        } else {
            while (cur != 0) {
                next = cur->mNext;
                if (link == next) {
                    break;
                }
                cur = next;
            }
            cur->mNext = bank->mWaveArcLink[index].mNext;
            DC_StoreRange(cur, 8);
        }
    }
    top = waveArc->mTopLink;
    waveArc->mTopLink = &bank->mWaveArcLink[index];
    bank->mWaveArcLink[index].mNext = top;
    bank->mWaveArcLink[index].mWaveArc = waveArc;
    SNDi_UnlockMutex();
    DC_StoreRange(bank, 0x3c);
    DC_StoreRange(waveArc, 0x3c);
}

// Takes each of the four entries of bank out of the list of the wave archive it is in.
void SND_DestroyBank(SNDBankData *bank) {
    s32 linkIndex;
    SNDWaveArc *waveArchive;
    SNDWaveArcLink *cur;
    SNDWaveArcLink *link;
    SNDWaveArcLink *next;

    SNDi_LockMutex();
    link = &bank->mWaveArcLink[0];
    for (linkIndex = 0; linkIndex < 4; linkIndex++) {
        waveArchive = bank->mWaveArcLink[linkIndex].mWaveArc;
        if (waveArchive != 0) {
            cur = waveArchive->mTopLink;
            if (link == cur) {
                waveArchive->mTopLink = bank->mWaveArcLink[linkIndex].mNext;
                DC_StoreRange(waveArchive, 0x3c);
            } else {
                while (cur != 0) {
                    next = cur->mNext;
                    if (link == next) {
                        break;
                    }
                    cur = next;
                }
                cur->mNext = bank->mWaveArcLink[linkIndex].mNext;
                DC_StoreRange(cur, 8);
            }
        }
        link++;
    }
    SNDi_UnlockMutex();
}

// Clears every entry in the list of waveArc.
void SND_DestroyWaveArc(SNDWaveArc *waveArc) {
    SNDWaveArcLink *cur;
    SNDWaveArcLink *next;

    SNDi_LockMutex();
    cur = waveArc->mTopLink;
    if (cur != 0) {
        do {
            next = cur->mNext;
            cur->mWaveArc = 0;
            cur->mNext = 0;
            DC_StoreRange(cur, 8);
            cur = next;
        } while (next != 0);
    }
    SNDi_UnlockMutex();
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
    InstDrumSet *drumSet;
    InstKeySplit *keySplit;

    while (pos->mPrgNo < bank->mInstCount) {
        entry = bank->mInstOffset[pos->mPrgNo];
        inst->mType = entry;
        switch (inst->mType) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                simple = OFFSET_PTR(InstSimple, bank, (entry >> 8));
                inst->mWave = simple->mWave;
                inst->mUnk_06 = simple->mUnk_04;
                inst->mUnk_0a = simple->mUnk_08;
                pos->mPrgNo++;
                return 1;
            case 0x10:
                drumSet = OFFSET_PTR(InstDrumSet, bank, (entry >> 8));
                while (pos->mIndex < drumSet->mMax - drumSet->mMin + 1) {
                    *inst = drumSet->mInstOffset[pos->mIndex];
                    pos->mIndex++;
                    return 1;
                }
                break;
            case 0x11:
                keySplit = OFFSET_PTR(InstKeySplit, bank, (entry >> 8));
                while (pos->mIndex < 8) {
                    if (keySplit->mKey[pos->mIndex] == 0) {
                        break;
                    }
                    *inst = keySplit->mInstOffset[pos->mIndex];
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
    SNDi_LockMutex();
    waveArc->mWaveOffset[index] = (u32) address;
    DC_StoreRange(&waveArc->mWaveOffset[index], 4);
    SNDi_UnlockMutex();
}
