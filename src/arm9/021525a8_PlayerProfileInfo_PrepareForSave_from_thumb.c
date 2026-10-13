/* Decompiled C draft; module arm9; ROM address 021525a8. No matching claim. */
#include "types.h"
#include "deps/021525a8_PlayerProfileInfo_PrepareForSave_from_thumb.h"

void PlayerProfileInfo_PrepareForSave_from_thumb(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_408 [1024];
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  GenerateProfileInfoCrcLookupTable((int)(uintptr_t)(auStack_408),uRam021525dc);
  uVar1 = ComputeProfileInfoCrc((undefined4)(uintptr_t)(auStack_408),param_1,0x3c);
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  return;
}

