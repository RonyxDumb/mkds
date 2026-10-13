/* Decompiled C draft; module arm9_ov000; ROM address 0219d49c. No matching claim. */
#include "types.h"
#include "deps/0219d49c_FUN_0219d49c.h"

undefined4 FUN_0219d49c(void)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  iVar2 = *DAT_0219d4ec;
  lVar4 = func_0x0200f5ac();
  lVar4 = lVar4 - *(longlong *)(iVar2 + 0xc);
  uVar1 = (uint)lVar4;
  uVar5 = func_0x02132e40(uVar1 * 0x40,(int)((ulonglong)lVar4 >> 0x20) * 0x40 | uVar1 >> 0x1a,
                          DAT_0219d4f0,0);
  uVar1 = (uint)((ulonglong)uVar5 >> 0x20);
  bVar3 = DAT_0219d4f4 <= (uint)uVar5;
  if (uVar1 != 0 || uVar1 < bVar3) {
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    FUN_0218f268(*(undefined4 *)(*DAT_0219d4ec + 4),uVar1 - !bVar3);
    uVar5 = func_0x0200f5ac();
    *(undefined8 *)(*DAT_0219d4ec + 0xc) = uVar5;
  }
  return 0;
}

