/* Decompiled C draft; module arm9; ROM address 020574c8. No matching claim. */
#include "types.h"
#include "deps/020574c8_Task_WriteSaveDataHeader_from_thumb.h"

void Task_WriteSaveDataHeader_from_thumb(void)

{
  if (*(int *)(*piRam020574fc + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_Header_from_thumb(*(undefined4 *)*puRam02057500);
  if (*(int *)(*piRam020574fc + 0xc) != 0) {
    func_02145d38();
  }
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

