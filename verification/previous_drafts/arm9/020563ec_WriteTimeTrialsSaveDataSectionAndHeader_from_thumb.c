/* Decompiled C draft; module arm9; ROM address 020563ec. No matching claim. */
#include "types.h"
#include "deps/020563ec_WriteTimeTrialsSaveDataSectionAndHeader_from_thumb.h"

void WriteTimeTrialsSaveDataSectionAndHeader_from_thumb(void)

{
  WriteSaveDataSection_TimeTrials_from_thumb(*(undefined4 *)(*piRam02056404 + 0xc));
  WriteSaveDataHeader_from_thumb();
  return;
}

