/* Decompiled C draft; module arm9; ROM address 020574a0. No matching claim. */
#include "types.h"
#include "deps/020574a0_WriteSaveDataHeader_from_thumb.h"

void WriteSaveDataHeader_from_thumb(void)

{
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam020574c0);
  *(undefined4 *)(*piRam020574c4 + 0xf8) = 1;
  return;
}

