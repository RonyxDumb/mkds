/* Decompiled C draft; module arm9; ROM address 02113174. No matching claim. */
#include "types.h"
#include "deps/02113174_func_02113174.h"

void func_02113174(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  int local_20;
  ushort *local_18;
  
  piVar1 = piRam02113264;
  *(undefined4 *)(*piRam02113264 + 0x50) = 0xb;
  local_20 = 0;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
  uVar3 = (uint)*(ushort *)(*(int *)(*piVar1 + 0x30) + 6);
  *(short *)(*(int *)(*piVar1 + 0x3c) + iRam02113268) = (short)uRam0211326c;
  *(short *)(*(int *)(*piVar1 + 0x3c) + iRam02113270) = (short)uRam0211326c;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02113274) = 0xff00;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02113278) = 0xff00;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam0211327c) = 0xff00;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + 5) * 0x40 + 4) = 0xff00;
  local_18 = puRam02113290;
  puVar5 = puRam0211328c;
  puVar6 = puRam02113288;
  puVar7 = puRam02113284;
  puVar8 = puRam02113280;
  do {
    *(short *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = (short)uRam0211326c;
    *(short *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = (short)uRam0211326c;
    *(short *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = (short)uRam0211326c;
    *(short *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar5 * 0x40 + 4) = (short)uRam0211326c;
    *(short *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + *local_18) * 0x40 + 4) = (short)uRam0211326c;
    piVar2 = piRam02113264;
    puVar8 = puVar8 + 1;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    local_18 = local_18 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  iVar4 = 0;
  puVar5 = puRam02113294;
  do {
    *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar5 * 0x40) = 0;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  func_021139b4();
  return;
}

