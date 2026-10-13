/* Decompiled C draft; module arm9; ROM address 02085984. No matching claim. */
#include "types.h"
#include "deps/02085984_func_02085984.h"

int func_02085984(uint param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint extraout_r1;
  short sVar5;
  int iVar6;
  longlong *plVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  
  bVar2 = false;
  iVar6 = -1;
  iVar9 = *(int *)(*piRam02085abc + iRam02085ac0);
  bVar1 = false;
  iVar3 = *piRam02085ac4;
  uVar8 = *(uint *)(iVar3 + param_1 * 0x30 + 0x70);
  if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    iVar6 = *param_2;
    *param_2 = iVar6 + -1;
  }
  else {
    if (iVar9 == 0) {
      uVar8 = (uint)(*(int *)(*piRam02085abc + iRam02085ac8) != 0);
      if (param_1 == (int)*(char *)(iVar3 + uVar8 + iRam02085acc)) {
        iVar6 = 1;
        bVar2 = true;
      }
      else if (param_1 == ((int)*(char *)(iVar3 + (uint)(uVar8 == 0) + iRam02085acc) & 0xffffU)) {
        iVar6 = 2;
        bVar2 = true;
      }
    }
    else {
      uVar8 = 0;
      do {
        if ((int)*(char *)(iVar3 + uVar8 + iRam02085acc) == param_1) {
          if (uVar8 == 0) {
            iVar6 = 1;
          }
          else {
            iVar6 = 2;
            if (iVar9 == 2) {
              iVar6 = 1;
            }
          }
          bVar2 = true;
          break;
        }
        uVar8 = uVar8 + 1 & 0xffff;
      } while (uVar8 < 2);
    }
    if (!bVar2) {
      iVar3 = *piRam02085abc + iRam02085ad0;
      sVar5 = *(short *)(iVar3 + 8);
      plVar7 = *(longlong **)(*piRam02085abc + iRam02085ad4);
      if (sVar5 == 1) {
        uVar8 = 0;
      }
      else {
        lVar10 = Multiply64((int)plVar7[1],*(undefined4 *)((int)plVar7 + 0xc),(int)*plVar7,
                            *(undefined4 *)((int)plVar7 + 4),param_2,iVar9 == 2,param_1 * 0x30);
        *plVar7 = lVar10 + plVar7[2];
        sVar5 = sVar5 + -1;
        if (sVar5 == 0) {
          uVar8 = *(uint *)((int)plVar7 + 4);
        }
        else {
          Multiply64(*(undefined4 *)((int)plVar7 + 4),0,sVar5,0);
          uVar8 = extraout_r1;
        }
      }
      piVar4 = (int *)IntrusiveListWrapper_GetAtIndex(iVar3,uVar8 & 0xffff);
      iVar6 = *piVar4;
      IntrusiveListWrapper_RemoveItem(iVar3);
    }
  }
  return iVar6;
}

