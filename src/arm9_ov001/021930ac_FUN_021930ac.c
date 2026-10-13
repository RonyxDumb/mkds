/* Decompiled C draft; module arm9_ov001; ROM address 021930ac. No matching claim. */
#include "types.h"
#include "deps/021930ac_FUN_021930ac.h"

void FUN_021930ac(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  *DAT_02193124 = *DAT_02193124 & DAT_0219312c | ((*DAT_02193124 & DAT_02193128) >> 8 | 1) << 8;
  puVar1 = DAT_02193130;
  *DAT_02193130 = *DAT_02193130 & 0x43 | (ushort)DAT_02193134;
  *puVar1 = *puVar1 & 0xfffc | 2;
  puVar1 = DAT_02193138;
  *DAT_02193138 = *DAT_02193138 & 0x43 | (ushort)DAT_0219313c;
  *puVar1 = *puVar1 & 0xfffc | 1;
  uVar2 = func_0x0214a2f4();
  func_0x0214d05c(0,(undefined4 *)(uintptr_t)(uVar2),DAT_02193140);
  uVar2 = func_0x0214a2a0();
  func_0x0214d05c(0,(undefined4 *)(uintptr_t)(uVar2),DAT_02193140);
  return;
}

