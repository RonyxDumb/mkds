/* Decompiled C draft; module arm7; ROM address 037f8228. No matching claim. */
#include "types.h"
#include "deps/037f8228_FUN_037f8228.h"

void FUN_037f8228(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 auStack_304 [11];
  byte abStack_2ee [54];
  byte abStack_2b8 [152];
  ushort local_220 [2];
  int local_21c;
  undefined1 auStack_218 [8];
  undefined4 local_210;
  undefined4 local_20c;
  undefined1 auStack_208 [256];
  undefined1 auStack_108 [256];
  
  FUN_03804bbc(0x20,2,&local_21c);
  local_21c = local_21c << 3;
  FUN_03804bbc(local_21c,0x100,auStack_208);
  FUN_03804bbc(local_21c + 0x100,0x100,auStack_108);
  iVar2 = FUN_037f802c(auStack_208);
  if (iVar2 < 3) {
    if (iVar2 == 0) {
      local_20c = 0;
      FUN_037fb24c(0,DAT_037f83b4,0x74);
    }
    else {
      if (*(byte *)((int)local_220 + iVar2 * 0x100 + DAT_037f83b8) < 10) {
        for (iVar3 = 10; (int)(uint)abStack_2ee[iVar2 * 0x100] < iVar3; iVar3 = iVar3 + -1) {
          auStack_304[iVar2 * 0x80 + iVar3] = 0;
        }
      }
      if (*(byte *)((int)local_220 + iVar2 * 0x100 + DAT_037f83bc) < 0x1a) {
        for (iVar3 = 0x1a; (int)(uint)abStack_2b8[iVar2 * 0x100] < iVar3; iVar3 = iVar3 + -1) {
          (abStack_2ee + iVar3 * 2 + iVar2 * 0x100)[0] = 0;
          (abStack_2ee + iVar3 * 2 + iVar2 * 0x100)[1] = 0;
        }
      }
      FUN_037fb260(auStack_208 + (iVar2 + -1) * 0x100,DAT_037f83b4,0x74);
    }
  }
  else {
    local_210 = 0xffffffff;
    FUN_037fb24c(0xffffffff,DAT_037f83b4,0x74);
  }
  FUN_03804bbc(0x36,6,auStack_218);
  iVar2 = DAT_037f83b4;
  FUN_037fb390(auStack_218,DAT_037f83b4 + 0x74,6);
  FUN_03804bbc(0x3c,2,local_220);
  uVar1 = FUN_038072f8(((uint)local_220[0] << 0xf) >> 0x10);
  *(undefined2 *)(iVar2 + 0x7a) = uVar1;
  return;
}

