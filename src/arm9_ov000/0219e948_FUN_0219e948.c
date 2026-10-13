/* Decompiled C draft; module arm9_ov000; ROM address 0219e948. No matching claim. */
#include "types.h"
#include "deps/0219e948_FUN_0219e948.h"

undefined1 FUN_0219e948(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)(param_2 == 0);
  iVar2 = *DAT_0219e98c;
  if (uVar1 <= *(byte *)(iVar2 + 0xd)) {
    iVar3 = iVar2 + uVar1 * 4;
    do {
      if (param_1 == *(int *)(iVar3 + 0xf4)) {
        return *(undefined1 *)(iVar2 + uVar1 + DAT_0219e990);
      }
      iVar3 = iVar3 + 4;
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)*(byte *)(iVar2 + 0xd));
  }
  return 0xff;
}

