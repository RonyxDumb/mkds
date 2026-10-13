/* Decompiled C draft; module arm9; ROM address 020f357c. No matching claim. */
#include "types.h"
#include "deps/020f357c_func_020f357c.h"

void func_020f357c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar1 = iRam020f3670;
  iVar6 = *piRam020f366c;
  uVar4 = (uint)*(ushort *)(iVar6 + 0x58);
  iVar7 = *(int *)(iVar6 + 0xac);
  uVar9 = 0;
  uVar5 = 0;
  do {
    *(undefined4 *)(iVar1 + uVar9 * 4) = 0;
    iVar3 = iRam020f3674;
    iVar2 = iRam020f3670;
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 4);
  if (uVar4 != 0) {
    do {
      if (iVar3 <= *(int *)(iVar7 + 0x1c)) {
        *(int *)(iVar2 + (uint)*(byte *)(iVar7 + 0x20) * 4) = iVar7;
      }
      uVar5 = uVar5 + 1 & 0xffff;
      iVar7 = iVar7 + 0x28;
    } while (uVar5 < uVar4);
  }
  piVar8 = *(int **)(iVar6 + 0xac);
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      VecFx32_Subtract(*(undefined4 *)(*piVar8 + 0x18),piVar8[6],&local_20);
      iVar1 = local_20;
      iVar6 = local_1c;
      lVar10 = Multiply64(local_18,local_18 >> 0x1f,local_18,local_18 >> 0x1f,uVar4,local_1c);
      lVar11 = Multiply64(iVar1,iVar1 >> 0x1f,iVar1,iVar1 >> 0x1f);
      lVar12 = Multiply64(iVar6,iVar6 >> 0x1f,iVar6,iVar6 >> 0x1f);
      lVar10 = lVar10 + lVar11 + lVar12;
      if ((int)(uint)((uint)lVar10 < 0x10) <= (int)((ulonglong)lVar10 >> 0x20)) {
        Vector3_MaybeNormalize(&local_20,&local_20);
      }
      *(char *)((int)piVar8 + 0x21) = (char)(local_20 >> 6);
      *(char *)((int)piVar8 + 0x22) = (char)(local_1c >> 6);
      *(char *)((int)piVar8 + 0x23) = (char)(local_18 >> 6);
      uVar5 = uVar5 + 1 & 0xffff;
      piVar8 = piVar8 + 10;
    } while (uVar5 < uVar4);
  }
  return;
}

