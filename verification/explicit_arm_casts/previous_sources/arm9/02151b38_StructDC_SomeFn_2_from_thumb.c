/* Decompiled C draft; module arm9; ROM address 02151b38. No matching claim. */
#include "types.h"
#include "deps/02151b38_StructDC_SomeFn_2_from_thumb.h"

undefined4 StructDC_SomeFn_2_from_thumb(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int local_30;
  int local_28 [5];
  
  iVar2 = StructDC_SomeFn_3_from_thumb();
  if (iVar2 == 0) {
    return uRam02151d7c;
  }
  SomeHashing(param_1 + iRam02151d80,uRam02151d84);
  iVar2 = StructDC_SomeFn_1_from_thumb(param_1);
  if (iVar2 == 0) {
    return uRam02151d7c;
  }
  Mem_CpuFill8(local_28,0,0x10);
  local_30 = 0;
  piVar6 = local_28;
  iVar2 = param_1;
  iVar7 = param_1;
  do {
    uVar3 = func_020205e8(param_1 + iRam02151d80,iVar2,0xfe);
    if ((uVar3 == *(ushort *)(iVar2 + 0xfe)) &&
       (iVar4 = StructDCSub_SomeFn_from_thumb(iVar7), iVar4 != 0)) {
      *piVar6 = 1;
    }
    iVar2 = iVar2 + iRam02151d88;
    iVar7 = iVar7 + iRam02151d88;
    piVar6 = piVar6 + 1;
    local_30 = local_30 + 1;
  } while (local_30 < 3);
  uVar3 = func_020205e8(param_1 + iRam02151d80,param_1 + iRam02151d8c,0xfe);
  if (uVar3 == *(ushort *)(param_1 + iRam02151d90)) {
    local_28[3] = 1;
  }
  if ((((local_28[0] != 0) && (local_28[1] != 0)) && (local_28[2] != 0)) && (local_28[3] != 0)) {
    func_02151708(param_1 + 0xf0);
    return 0;
  }
  if (((local_28[0] == 0) && (local_28[1] == 0)) && ((local_28[2] == 0 && (local_28[3] == 0)))) {
    StructDC_SomeFn_from_thumb(param_1);
    iVar2 = StructDC_SomeFn_0_from_thumb(param_1);
    if (iVar2 != 0) {
      return 0;
    }
    return uRam02151d94;
  }
  if (((local_28[0] == 0) || (local_28[1] == 0)) && ((local_28[2] == 0 || (local_28[3] == 0)))) {
    StructDC_SomeFn_from_thumb(param_1);
    iVar2 = StructDC_SomeFn_0_from_thumb(param_1);
    if (iVar2 != 0) {
      return 0;
    }
    return uRam02151d94;
  }
  if ((local_28[0] == 0) && (local_28[1] == 0)) {
    StructDC_SomeFn_from_thumb(param_1);
    iVar2 = StructDC_SomeFn_0_from_thumb(param_1);
    if (iVar2 != 0) {
      return uRam02151d98;
    }
    return uRam02151d94;
  }
  if (local_28[0] == 0) {
    StructDC_CleanDCSub_from_thumb(param_1,0);
    Mem_CpuCopy8(param_1 + iRam02151d9c,param_1 + 0xf0,0xd);
    *(undefined1 *)(param_1 + 0xef) = *(undefined1 *)(param_1 + iRam02151da0);
  }
  else if (local_28[1] == 0) {
    StructDC_CleanDCSub_from_thumb(param_1,1);
    Mem_CpuCopy8(param_1 + 0xf0,param_1 + iRam02151d9c,0xd);
    *(undefined1 *)(param_1 + iRam02151da0) = *(undefined1 *)(param_1 + 0xef);
  }
  func_02151708(param_1 + 0xf0);
  if (local_28[2] == 0) {
    StructDC_CleanDCSub_from_thumb(param_1,2);
  }
  if (local_28[3] == 0) {
    Mem_CpuFill16(0,param_1 + iRam02151d8c,iRam02151d88);
  }
  bVar1 = false;
  uVar3 = 0;
  piVar6 = local_28;
  do {
    if ((*piVar6 == 0) && (uVar5 = 1 << (uVar3 & 0xff), (*(byte *)(param_1 + 0xef) & uVar5) != 0)) {
      *(byte *)(param_1 + 0xef) = *(byte *)(param_1 + 0xef) & ~(byte)uVar5;
      bVar1 = true;
    }
    piVar6 = piVar6 + 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 3);
  iVar2 = StructDC_SomeFn_0_from_thumb(param_1);
  if (iVar2 == 0) {
    return uRam02151d94;
  }
  if (bVar1) {
    return uRam02151da4;
  }
  return 0;
}

