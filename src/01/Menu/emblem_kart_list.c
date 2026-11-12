#include "01/Menu/emblem_kart_list.h"
#include "01/MapObjects/lld.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/unk_021a6000.h"
#include "Main/Kart/kart_model_menu.h"
#include "gx_load2d.h"

void AdvanceEmblemKartList(void) {
    int kartListNumber;
    int kartListCount;

    kartListNumber = GetKartListNumber();
    kartListCount = GetKartListCount();
    AdvanceKartModelMenuInput();
    if (kartListCount >= 10) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), kartListCount / 10);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount % 10);
        if (kartListNumber >= 10) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), kartListNumber / 10);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber % 10);
        } else {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber);
        }
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), -5);
    } else {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), kartListNumber);
    }
}
