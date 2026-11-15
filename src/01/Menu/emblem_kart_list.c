#include "01/Menu/emblem_kart_list.h"
#include "01/MapObjects/lld.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Kart/kart_model_menu.h"
#include "vram_load_2d_graphics.h"

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
