/* Decompiled C draft; module arm9; ROM address 02047468. No matching claim. */
#include "types.h"
#include "deps/02047468_Maybe_s_s.h"

void Maybe_s_s(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_8c [128];
  
  uVar1 = GetSomeLanguage_from_thumb();
  Util_SNPrintF(auStack_8c,0x80,uRam02047494,param_1,uVar1);
  func_02047498((undefined4)(uintptr_t)(auStack_8c),param_2);
  return;
}

