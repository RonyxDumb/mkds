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
    oldArc = bank->field18[index].field0;
    if (oldArc != 0) {
        if (waveArc == oldArc) {
            SNDi_UnlockMutex();
            return;
        }
        cur = oldArc->field18[0].field0;
        link = &bank->field18[index];
        if (link == cur) {
            oldArc->field18[0].field0 = bank->field18[index].field4;
            DC_StoreRange(bank->field18[index].field0, 0x3c);
        } else {
            while (cur != 0) {
                next = cur->field4;
                if (link == next) {
                    break;
                }
                cur = next;
            }
            cur->field4 = bank->field18[index].field4;
            DC_StoreRange(cur, 8);
        }
    }
    top = waveArc->field18[0].field0;
    waveArc->field18[0].field0 = &bank->field18[index];
    bank->field18[index].field4 = top;
    bank->field18[index].field0 = waveArc;
    SNDi_UnlockMutex();
    DC_StoreRange(bank, 0x3c);
    DC_StoreRange(waveArc, 0x3c);
}

// Takes each of the four entries of bank out of the list of the wave archive it is in.
void SND_DestroyBank(Unk02021968 *bank) {
    s32 i;
    Unk02021968 *waveArchive;
    Unk02021be8 *cur;
    Unk02021be8 *link;
    Unk02021be8 *next;

    SNDi_LockMutex();
    link = &bank->field18[0];
    for (i = 0; i < 4; i++) {
        waveArchive = bank->field18[i].field0;
        if (waveArchive != 0) {
            cur = waveArchive->field18[0].field0;
            if (link == cur) {
                waveArchive->field18[0].field0 = bank->field18[i].field4;
                DC_StoreRange(waveArchive, 0x3c);
            } else {
                while (cur != 0) {
                    next = cur->field4;
                    if (link == next) {
                        break;
                    }
                    cur = next;
                }
                cur->field4 = bank->field18[i].field4;
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
    cur = waveArc->field18[0].field0;
    if (cur != 0) {
        do {
            next = cur->field4;
            cur->field0 = 0;
            cur->field4 = 0;
            DC_StoreRange(cur, 8);
            cur = next;
        } while (next != 0);
    }
    SNDi_UnlockMutex();
}

// Sets pos to the start of the instrument entries.
void SND_GetFirstInstDataPos(Unk02021bc8 *pos) {
    Unk02021bc8 first;

    first.field0 = 0;
    first.field4 = 0;
    *pos = first;
}

// Copies the instrument entry at pos into inst and moves pos on; returns 0 when there are no more.
u32 SND_GetNextInstData(Unk02021968 *bank, Unk020219f0 *inst, Unk02021bc8 *pos) {
    u32 entry;
    Unk02021a60 *simple;
    Unk02021aa8 *drumSet;
    Unk02021b24 *keySplit;

    while (pos->field0 < bank->field38) {
        entry = bank->field3C[pos->field0];
        inst->field0 = entry;
        switch (inst->field0) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                simple = OFFSET_PTR(Unk02021a60, bank, (entry >> 8));
                *(Unk02021a5c *) &inst->field2 = simple->field0;
                *(Unk02021a5c *) &inst->field6 = simple->field4;
                inst->fieldA = simple->field8;
                pos->field0++;
                return 1;
            case 0x10:
                drumSet = OFFSET_PTR(Unk02021aa8, bank, (entry >> 8));
                while (pos->field4 < drumSet->field1 - drumSet->field0 + 1) {
                    *(Unk02021ab0 *) inst = drumSet->field2[pos->field4];
                    pos->field4++;
                    return 1;
                }
                break;
            case 0x11:
                keySplit = OFFSET_PTR(Unk02021b24, bank, (entry >> 8));
                while (pos->field4 < 8) {
                    if (keySplit->field0[pos->field4] == 0) {
                        break;
                    }
                    *(Unk02021ab0 *) inst = keySplit->field8[pos->field4];
                    pos->field4++;
                    return 1;
                }
                break;
        }
        pos->field0++;
        pos->field4 = 0;
    }
    return 0;
}

// Returns the number of wave data entries of waveArc.
u32 SND_GetWaveDataCount(Unk02021968 *waveArc) {
    return waveArc->field38;
}
