/* Decompiled C draft; module arm9_ov000; ROM address 021aea34. No matching claim. */
#include "types.h"
#include "deps/021aea34_FUN_021aea34.h"

void FUN_021aea34(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar3 = (undefined4 *)FUN_021af090();
  if (puVar3 == (undefined4 *)0x0) {
    FUN_021aeed8(param_1,(ushort *)(uintptr_t)(param_2),param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 9);
    return;
  }
  bVar2 = *(byte *)(param_2 + 0xd);
  uVar6 = (uint)bVar2;
  puVar3[0xc] = ((int)(uint)*(ushort *)(param_2 + 8) >> 8 | (*(ushort *)(param_2 + 8) & 0xff) << 8)
                << 0x10 | (int)(uint)*(ushort *)(param_2 + 10) >> 8 |
                          (*(ushort *)(param_2 + 10) & 0xff) << 8;
  uVar8 = (int)(uint)*(ushort *)(param_2 + 6) >> 8;
  uVar7 = (uint)*(ushort *)(param_2 + 6) << 8;
  uVar9 = uVar8 | uVar7;
  uVar7 = ((int)(uint)*(ushort *)(param_2 + 4) >> 8 | (*(ushort *)(param_2 + 4) & 0xff) << 8) <<
          0x10 | uVar8 | uVar7 & 0xffff;
  if ((*(char *)(puVar3 + 2) == '\x04') && (puVar3[9] != uVar7)) {
    FUN_021aefb4((undefined4)(uintptr_t)(puVar3),(ushort)*(byte *)(param_1 + 5) * 0x100 + 10);
    return;
  }
  *(ushort *)(puVar3 + 0xb) = *(ushort *)(param_2 + 0xe) >> 8 | *(ushort *)(param_2 + 0xe) << 8;
  switch(*(undefined1 *)(puVar3 + 2)) {
  case 0:
  case 2:
    FUN_021aeed8(param_1,(ushort *)(uintptr_t)(param_2),param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 99);
    break;
  default:
    if ((bVar2 & 1) != 0) {
      puVar3[9] = puVar3[9] + 1;
    }
    FUN_021aefb4(puVar3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x12,uVar7,uVar9,uVar6 & 1);
    break;
  case 3:
    *(undefined1 *)(puVar3 + 2) = 4;
    if (puVar3[1] == 1) {
      puVar3[1] = 0;
      func_0x0200df68(*puVar3);
    }
    if (param_3 == 0) break;
  case 4:
    puVar3[0xd] = puVar3[0xd] + 1;
    uVar7 = puVar3[0xf] - puVar3[0x11];
    bVar1 = uVar7 < param_3;
    if (bVar1) {
      param_3 = uVar7;
    }
    if (param_3 != 0) {
      uVar4 = func_0x0200fca0();
      iVar5 = func_0x02133068(*(byte *)(param_2 + 0xc) & 0xf0,4);
      func_0x0214d1fc((ushort *)(uintptr_t)(param_2 + iVar5),(uint *)(uintptr_t)(puVar3[0x10] + puVar3[0x11]),param_3);
      puVar3[0x11] = puVar3[0x11] + param_3;
      puVar3[9] = puVar3[9] + param_3;
      func_0x0200fcb4(uVar4);
      if (puVar3[1] == 2) {
        puVar3[1] = 0;
        func_0x0200df68(*puVar3);
      }
    }
    if ((bVar1) || ((uVar6 & 1) == 0)) {
      if (param_3 != 0) {
        FUN_021aefb4((undefined4)(uintptr_t)(puVar3),(ushort)*(byte *)(param_1 + 5) * 0x100 + 0xc);
      }
    }
    else {
      *(undefined1 *)(puVar3 + 2) = 6;
      puVar3[9] = puVar3[9] + 1;
      FUN_021aefa8((undefined4)(uintptr_t)(puVar3),(ushort)*(byte *)(param_1 + 5) * 0x100 + 0xb);
      if ((param_3 == 0) && (puVar3[1] == 2)) {
        puVar3[1] = 0;
        func_0x0200df68(*puVar3);
      }
    }
    break;
  case 6:
  case 9:
    *(undefined1 *)(puVar3 + 2) = 0;
    if (puVar3[1] == 2) {
      puVar3[1] = 0;
      func_0x0200df68(*puVar3);
    }
    break;
  case 7:
  case 8:
    if ((bVar2 & 1) == 0) {
      if (param_3 != 0) {
        puVar3[9] = puVar3[9] + param_3;
        FUN_021aefb4(puVar3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0xe,uVar7,uVar9,uVar6 & 1);
      }
      *(undefined1 *)(puVar3 + 2) = 8;
    }
    else {
      puVar3[9] = puVar3[9] + param_3 + 1;
      FUN_021aefb4(puVar3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0xd,uVar7,uVar9,uVar6 & 1);
      *(undefined1 *)(puVar3 + 2) = 0;
      if (puVar3[1] == 2) {
        puVar3[1] = 0;
        func_0x0200df68(*puVar3);
      }
    }
  }
  func_0x0200dd94();
  return;
}

