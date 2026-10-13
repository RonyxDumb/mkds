/* Decompiled C draft; module arm9; ROM address 0202469c. No matching claim. */
#include "types.h"
#include "deps/0202469c_NFTR_Process.h"

int NFTR_Process(uint param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int unaff_r4;
  
  if (param_1 == 0) {
    bVar1 = false;
  }
  else {
    if ((param_1 == 0) ||
       ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != uRam020247f4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      if ((param_1 == 0) || (*(short *)(param_1 + 6) != 0x100)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
  }
  if (bVar1) {
    unaff_r4 = 0;
  }
  else {
    if (param_1 == 0) {
      bVar1 = false;
    }
    else {
      if ((param_1 == 0) ||
         ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != uRam020247f4)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        if ((param_1 == 0) || (*(short *)(param_1 + 6) != 1)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
    }
    if (bVar1) {
      unaff_r4 = 1;
    }
    else {
      Os_Terminate();
    }
  }
  NFTR_MakeAbsoluteOffsets(param_1);
  iVar2 = Common_FindBlockByMagic(param_1,uRam020247f8);
  if (iVar2 == 0) {
    *param_2 = 0;
    return 0;
  }
  *param_2 = iVar2 + 8;
  if (unaff_r4 != 0) {
    uVar3 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    *(undefined1 *)(uVar3 + 7) = *(undefined1 *)(uVar3 + 6);
    *(undefined1 *)
     ((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
      *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) + 6) = 0;
  }
  return unaff_r4 + 1;
}

