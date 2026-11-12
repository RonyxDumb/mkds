#pragma once

#include "types.h"

// Four callbacks handed over as one block.
typedef struct OptionStateCallbackTable {
    /* 00 */ UnkFunc *mCallbacks[4];
} OptionStateCallbackTable;

#include "01/code_02192000.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/unk_021a9000.h"
#include "01/code_02192e78.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/unk_021a6000.h"
#include "Main/Scene/display_settings.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/result_archive_path.h"

extern const OptionStateCallbackTable gOptionEmbremSelectCallbacks;

void RegisterOptionEmbremSelectCallbacks(void);
void WriteOptionEmbremSelectRegisters(void);
void AdvanceOptionEmbremSelect(void);
void AdvanceOptionEmbremSelectTimers(void);
void UpdateOptionEmbremSelectHighlight(void);
void UpdateOptionEmbremSelectIndexCells(void);
void UpdateOptionEmbremSelectCellOffsets(void);
void AdvanceOptionEmbremSelectState6(void);
void AdvanceOptionEmbremSelectState5(void);
void AdvanceOptionEmbremSelectState4(void);
void AdvanceOptionEmbremSelectState3(void);
void AdvanceOptionEmbremSelectState2(void);
void AdvanceOptionEmbremSelectState1(void);
void AdvanceOptionEmbremSelectState0(void);
BOOL IsBackupEmblemOff(void);
void LocateAndQueueOptionEmbremSelect(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionEmbremSelect(void);
void InitOptionEmbremSelect(void *heap);

#include "00/code_021832d8.h"
