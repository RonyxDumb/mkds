/* Decompiled C draft; module arm9; ROM address 020875b4. No matching claim. */
#include "types.h"
#include "deps/020875b4_CreateGlobalAED0_from_thumb.h"

void CreateGlobalAED0_from_thumb(void)

{
  undefined2 uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  GetActiveExecutionContext();
  uVar7 = ExecutionContext_GetHeapHandle();
  bVar13 = *(int *)(*piRam02087804 + 8) == 0;
  iVar8 = Mem_AllocateHeap(uVar7,uRam02087808);
  piVar5 = piRam0208780c;
  *piRam0208780c = iVar8;
  *(undefined4 *)(iVar8 + iRam02087810) = 0;
  *(undefined4 *)(*piVar5 + iRam02087814) = 0;
  iVar9 = IsAwardOrStaffRoll_0();
  iVar8 = iRam02087818;
  piVar6 = piRam0208780c;
  piVar5 = piRam02087804;
  if (iVar9 == 0) {
    if (bVar13) {
      *(uint *)(*piRam0208780c + 0x20) = (uint)*(byte *)(*piRam02087804 + iRam0208781c);
      uVar11 = (uint)*(char *)(*piVar5 + 0x62);
      bVar2 = false;
      if (uVar11 != 0xffffffff) {
        uVar11 = *(uint *)(*piVar5 + (uVar11 & 0xffff) * 0x30 + 0x70);
        if ((uVar11 < 4) && ((1 << (uVar11 & 0xff) & 0xdU) != 0)) {
          bVar2 = true;
        }
        if (bVar2) {
          *(int *)(*piRam0208780c + 0x20) = *(int *)(*piRam0208780c + 0x20) + -1;
        }
      }
    }
    else {
      *(uint *)(*piRam0208780c + 0x20) = *(byte *)(*piRam02087804 + iRam02087818) - 1;
      uVar11 = 0;
      iVar9 = *piVar5;
      if (*(char *)(iVar9 + iVar8) != '\0') {
        do {
          iVar9 = iVar9 + uVar11 * 0x30;
          if ((*(int *)(iVar9 + 0x70) == 2) && (*(int *)(iVar9 + 0x80) == 0)) {
            *(int *)(*piVar6 + 0x20) = *(int *)(*piVar6 + 0x20) + -1;
          }
          uVar11 = uVar11 + 1 & 0xffff;
          iVar9 = *piVar5;
        } while (uVar11 < *(byte *)(iVar9 + iVar8));
      }
    }
  }
  else {
    *(undefined4 *)(*piRam0208780c + 0x20) = 0;
  }
  *puRam02087824 = uRam02087820;
  LoadEmblemDataInAED0_from_thumb();
  piVar6 = piRam0208780c;
  piVar5 = piRam02087804;
  uVar12 = 0;
  iVar8 = *piRam02087804;
  uVar11 = (uint)*(byte *)(iVar8 + iRam02087818);
  if (uVar11 != 0) {
    do {
      iVar9 = uVar12 * 2;
      uVar1 = (undefined2)uVar12;
      *(undefined2 *)(*piVar6 + iVar9 + 0x24) = uVar1;
      *(undefined2 *)(*piVar6 + iVar9 + 0x44) = uVar1;
      *(undefined2 *)(*piVar6 + iVar9 + 0x94) = uVar1;
      *(undefined2 *)(*piVar6 + iVar9 + 0x34) = 0;
      *(undefined2 *)(*piVar6 + iVar9 + 0x84) = 0;
      iVar8 = uVar12 * 4;
      *(undefined4 *)(*piVar6 + iVar8 + 0x54) = 0;
      *(undefined4 *)(*piVar6 + iVar8 + 0xa4) = 0;
      *(undefined2 *)(*piVar6 + iVar9 + 0x74) = uVar1;
      *(undefined2 *)(*piVar6 + iVar9 + 0x94) = uVar1;
      *(undefined4 *)(*piVar6 + iVar8 + iRam02087828) = 0;
      *(undefined4 *)(*piVar6 + iVar8) = 0;
      *(undefined4 *)(*piVar6 + iVar8 + 0xe4) = 0;
      uVar12 = uVar12 + 1 & 0xffff;
      iVar8 = *piVar5;
      uVar11 = (uint)*(byte *)(iVar8 + iRam02087818);
    } while (uVar12 < uVar11);
  }
  if ((0 < *(int *)(*piRam0208780c + 0x20)) && (uVar12 = 0, uVar11 != 0)) {
    iVar9 = 0;
    bVar2 = false;
    do {
      bVar4 = false;
      if (bVar13) {
        uVar11 = *(uint *)(iVar8 + uVar12 * 0x30 + 0x70);
        bVar3 = bVar2;
        if ((uVar11 < 4) && ((1 << (uVar11 & 0xff) & 0xdU) != 0)) {
          bVar3 = true;
        }
        if ((bVar3) && (uVar12 != (int)*(char *)(iVar8 + 0x62))) {
          bVar4 = true;
        }
      }
      else {
        bVar4 = bVar2;
        if ((uVar12 != (int)*(char *)(iVar8 + 0x62)) &&
           ((iVar8 = iVar8 + uVar12 * 0x30, *(int *)(iVar8 + 0x70) != 2 ||
            (*(int *)(iVar8 + 0x80) != 0)))) {
          bVar4 = true;
        }
      }
      if (bVar4) {
        uVar10 = Mem_AllocateHeap(uVar7,0x28);
        *(undefined4 *)(*piRam0208780c + uVar12 * 4) = uVar10;
        uVar10 = *(undefined4 *)(*piRam0208780c + uVar12 * 4);
        StructAER_SomeFn_from_thumb(uVar10,uVar12,uVar7);
        *(undefined4 *)(*piRam0208780c + iVar9 + 0xc4) = uVar10;
        iVar9 = iVar9 + 4;
      }
      else {
        *(undefined4 *)(*piRam0208780c + uVar12 * 4) = 0;
      }
      uVar12 = uVar12 + 1 & 0xffff;
      iVar8 = *piRam02087804;
    } while (uVar12 < *(byte *)(iVar8 + iRam02087818));
  }
  *puRam0208782c = 0;
  G3i_OrthoW_(uRam0208783c,uRam02087840,uRam02087844,uRam02087848,0,uRam02087830,uRam02087834,1,
              uRam02087838);
  return;
}

