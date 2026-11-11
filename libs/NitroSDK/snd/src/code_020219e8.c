#include "code_020219e8.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "snd_main.h"

// Links entry index of bank into the list of waveArc, first taking it out of the list of the wave archive it was in.
void SND_AssignWaveArc(Unk02021968 *bank, s32 index, Unk02021968 *waveArc) {
    Unk02021968 *oldArc;
    Unk02021be8 *cur;
    Unk02021be8 *link;
    Unk02021be8 *top;
    Unk02021be8 *next;

    SNDi_LockMutex();
    oldArc = bank->mUnk_18[index].mUnk_00;
    if (oldArc != 0) {
        if (waveArc == oldArc) {
            SNDi_UnlockMutex();
            return;
        }
        cur = oldArc->mUnk_18[0].mUnk_00;
        link = &bank->mUnk_18[index];
        if (link == cur) {
            oldArc->mUnk_18[0].mUnk_00 = bank->mUnk_18[index].mUnk_04;
            DC_StoreRange(bank->mUnk_18[index].mUnk_00, 0x3c);
        } else {
            while (cur != 0) {
                next = cur->mUnk_04;
                if (link == next) {
                    break;
                }
                cur = next;
            }
            cur->mUnk_04 = bank->mUnk_18[index].mUnk_04;
            DC_StoreRange(cur, 8);
        }
    }
    top = waveArc->mUnk_18[0].mUnk_00;
    waveArc->mUnk_18[0].mUnk_00 = &bank->mUnk_18[index];
    bank->mUnk_18[index].mUnk_04 = top;
    bank->mUnk_18[index].mUnk_00 = waveArc;
    SNDi_UnlockMutex();
    DC_StoreRange(bank, 0x3c);
    DC_StoreRange(waveArc, 0x3c);
}

// Takes each of the four entries of bank out of the list of the wave archive it is in.
void SND_DestroyBank(Unk02021968 *bank) {
    s32 linkIndex;
    Unk02021968 *waveArchive;
    Unk02021be8 *cur;
    Unk02021be8 *link;
    Unk02021be8 *next;

    SNDi_LockMutex();
    link = &bank->mUnk_18[0];
    for (linkIndex = 0; linkIndex < 4; linkIndex++) {
        waveArchive = bank->mUnk_18[linkIndex].mUnk_00;
        if (waveArchive != 0) {
            cur = waveArchive->mUnk_18[0].mUnk_00;
            if (link == cur) {
                waveArchive->mUnk_18[0].mUnk_00 = bank->mUnk_18[linkIndex].mUnk_04;
                DC_StoreRange(waveArchive, 0x3c);
            } else {
                while (cur != 0) {
                    next = cur->mUnk_04;
                    if (link == next) {
                        break;
                    }
                    cur = next;
                }
                cur->mUnk_04 = bank->mUnk_18[linkIndex].mUnk_04;
                DC_StoreRange(cur, 8);
            }
        }
        link++;
    }
    SNDi_UnlockMutex();
}

// Clears every entry in the list of waveArc.
void SND_DestroyWaveArc(Unk02021968 *waveArc) {
    Unk02021be8 *cur;
    Unk02021be8 *next;

    SNDi_LockMutex();
    cur = waveArc->mUnk_18[0].mUnk_00;
    if (cur != 0) {
        do {
            next = cur->mUnk_04;
            cur->mUnk_00 = 0;
            cur->mUnk_04 = 0;
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
u32 SND_GetNextInstData(Unk02021968 *bank, SNDInstData *inst, SNDInstPos *pos) {
    u32 entry;
    Unk02021a60 *simple;
    Unk02021aa8 *drumSet;
    Unk02021b24 *keySplit;

    while (pos->mPrgNo < bank->mUnk_38) {
        entry = bank->mUnk_3c[pos->mPrgNo];
        inst->mType = entry;
        switch (inst->mType) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                simple = OFFSET_PTR(Unk02021a60, bank, (entry >> 8));
                inst->mWave = simple->mUnk_00;
                inst->mUnk_06 = simple->mUnk_04;
                inst->mUnk_0a = simple->mUnk_08;
                pos->mPrgNo++;
                return 1;
            case 0x10:
                drumSet = OFFSET_PTR(Unk02021aa8, bank, (entry >> 8));
                while (pos->mIndex < drumSet->mUnk_01 - drumSet->mUnk_00 + 1) {
                    *inst = drumSet->mUnk_02[pos->mIndex];
                    pos->mIndex++;
                    return 1;
                }
                break;
            case 0x11:
                keySplit = OFFSET_PTR(Unk02021b24, bank, (entry >> 8));
                while (pos->mIndex < 8) {
                    if (keySplit->mUnk_00[pos->mIndex] == 0) {
                        break;
                    }
                    *inst = keySplit->mUnk_08[pos->mIndex];
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
u32 SND_GetWaveDataCount(Unk02021968 *waveArc) {
    return waveArc->mUnk_38;
}
