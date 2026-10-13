/* Decompiled C draft; module arm9_ov003; ROM address 021cd6d0. No matching claim. */
#include "types.h"
#include "deps/021cd6d0_FUN_021cd6d0.h"

void FUN_021cd6d0(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar6 = (undefined1 *)(*DAT_021cd788 + DAT_021cd78c);
  puVar5 = (undefined1 *)(*DAT_021cd788 + (uint)(byte)puVar6[0xf4] * 0x100);
  iVar2 = 0xf0;
  puVar3 = puVar5;
  puVar4 = puVar6;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (puVar6[0xf5] == '\0') {
    func_0x0214d1fc(puVar6 + 0xc0,puVar5 + 0xc0,4);
    func_0x0214d1fc(puVar6 + 0xc4,puVar5 + 0xc4,4);
    uVar1 = func_0x021516d8(puVar6 + 0xf0);
    puVar5[0xd0] = uVar1;
  }
  else {
    func_0x0214d168(puVar5 + 0xc0,0,4);
    func_0x0214d168(puVar5 + 0xc4,0,4);
    puVar5[0xd0] = 0;
  }
  if (puVar6[0xf6] == '\0') {
    func_0x0214d1fc(puVar6 + 200,puVar5 + 200,8);
  }
  else {
    func_0x0214d168(puVar5 + 200,0,8);
  }
  FUN_021cd338(puVar6[0xf4]);
  return;
}

