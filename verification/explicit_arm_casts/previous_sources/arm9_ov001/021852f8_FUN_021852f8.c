/* Decompiled C draft; module arm9_ov001; ROM address 021852f8. No matching claim. */
#include "types.h"
#include "deps/021852f8_FUN_021852f8.h"

ushort * FUN_021852f8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_20;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  puVar2 = (ushort *)func_0x02036bec(uVar1,0x18);
  puVar3 = (ushort *)func_0x0204799c(param_1);
  *puVar2 = *puVar3;
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar1 = func_0x02036bec(uVar1,(uint)*puVar2 * 0x88);
  *(undefined4 *)(puVar2 + 2) = uVar1;
  *(undefined4 *)(puVar2 + 4) = param_2;
  *(undefined4 *)(puVar2 + 6) = param_3;
  puVar3 = puVar3 + 1;
  local_20 = 0;
  if (*puVar2 != 0) {
    iVar6 = 0;
    do {
      iVar4 = *(int *)(puVar2 + 2);
      iVar5 = iVar4 + iVar6;
      *(ushort **)(iVar5 + 0x80) = puVar2;
      *(ushort *)(iVar4 + iVar6) = *puVar3;
      if (puVar3[1] == 0) {
        uVar1 = func_0x02132440(0);
        func_0x021329f8(uVar1,DAT_02185430);
      }
      else {
        uVar1 = func_0x02132440((uint)puVar3[1] << 0xc);
        func_0x02131234(DAT_02185430,uVar1);
      }
      uVar1 = func_0x021322c8();
      *(undefined4 *)(iVar5 + 4) = uVar1;
      if (puVar3[2] == 0) {
        uVar1 = func_0x02132440(0);
        func_0x021329f8(uVar1,DAT_02185430);
      }
      else {
        uVar1 = func_0x02132440((uint)puVar3[2] << 0xc);
        func_0x02131234(DAT_02185430,uVar1);
      }
      uVar1 = func_0x021322c8();
      *(undefined4 *)(iVar5 + 8) = uVar1;
      *(undefined4 *)(iVar5 + 0x18) = DAT_02185434;
      *(uint *)(iVar5 + 0xc) = (uint)(puVar3[3] != 0);
      uVar1 = func_0x02021db0(param_3,*puVar3);
      func_0x02022904(iVar5 + 0x2c,uVar1,param_2);
      if (puVar3[3] < 2) {
        *(undefined4 *)(iVar5 + 0x34) = 0;
      }
      else {
        *(undefined4 *)(iVar5 + 0x34) = 1;
      }
      iVar4 = *(int *)(iVar5 + 0x58);
      if (((int)(uint)*(ushort *)(iVar4 + 2) >> 0xb & 1U) != 0) {
        *(int *)(iVar5 + 0x1c) = (int)*(short *)(iVar4 + 0xc) << 0xc;
        *(int *)(iVar5 + 0x24) = (int)*(short *)(iVar4 + 0xe) << 0xc;
        *(int *)(iVar5 + 0x20) = (int)*(short *)(iVar4 + 8) << 0xc;
        *(int *)(iVar5 + 0x28) = (int)*(short *)(iVar4 + 10) << 0xc;
      }
      iVar6 = iVar6 + 0x88;
      puVar3 = puVar3 + 4;
      local_20 = local_20 + 1;
    } while (local_20 < (int)(uint)*puVar2);
  }
  return puVar2;
}

