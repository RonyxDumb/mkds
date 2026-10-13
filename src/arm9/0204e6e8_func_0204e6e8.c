/* Decompiled C draft; module arm9; ROM address 0204e6e8. No matching claim. */
#include "types.h"
#include "deps/0204e6e8_func_0204e6e8.h"

void func_0204e6e8(uint param_1,int param_2,byte *param_3)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  
  piVar3 = DAT_0204e908;
  *(int *)(*DAT_0204e908 + param_1 * 4 + DAT_0204e90c) = param_2;
  iVar7 = DAT_0204e920;
  iVar5 = DAT_0204e914;
  iVar4 = *piVar3;
  if ((*(int *)(iVar4 + 0xc) != 0x1b) || (param_2 == 0xc)) {
    switch(param_2) {
    case 1:
      *(undefined4 *)(iVar4 + 0x10) = 0;
      return;
    case 3:
      uVar8 = 1 << (param_1 & 0xff);
      if ((*(byte *)(iVar4 + DAT_0204e91c) & uVar8) != 0) {
        *(byte *)(iVar4 + DAT_0204e920) = *(byte *)(iVar4 + DAT_0204e920) | (byte)uVar8;
        iVar5 = *DAT_0204e908;
        if (*(byte *)(iVar5 + DAT_0204e918) ==
            (*(byte *)(iVar5 + DAT_0204e918) & *(byte *)(iVar5 + iVar7))) {
          *(undefined4 *)(iVar5 + 0x10) = 0;
        }
      }
      iVar5 = DAT_0204e924;
      piVar3 = DAT_0204e908;
      iVar7 = *DAT_0204e908;
      if ((*(byte *)(iVar7 + DAT_0204e910) & 2) == 0) {
        if (*(char *)(iVar7 + DAT_0204e924) == '\0') {
          *(undefined1 *)(iVar7 + DAT_0204e918) = 0;
          *(undefined1 *)(*piVar3 + DAT_0204e920) = 0;
          *(undefined1 *)(*piVar3 + DAT_0204e91c) = 0;
          *(undefined1 *)(*piVar3 + iVar5) = 0;
        }
        else {
          bVar1 = *(byte *)(iVar7 + DAT_0204e918);
          if ((bVar1 & uVar8) != 0) {
            *(byte *)(iVar7 + DAT_0204e918) = bVar1 & ~(byte)uVar8;
            pcVar6 = (char *)(*piVar3 + iVar5);
            *pcVar6 = *pcVar6 + -1;
          }
          if (((*(byte *)(*DAT_0204e908 + DAT_0204e910) & 1) != 0) &&
             (*(char *)(*DAT_0204e908 + DAT_0204e918) == '\0')) {
            func_02050e60(7);
          }
        }
      }
      iVar5 = *DAT_0204e908;
      if ((((*(byte *)(iVar5 + DAT_0204e910) & 2) != 0) &&
          (*(byte *)(iVar5 + DAT_0204e918) ==
           (*(byte *)(iVar5 + DAT_0204e918) & *(byte *)(iVar5 + DAT_0204e920)))) &&
         (*(int *)(iVar5 + 0xc) == 0x19)) {
        *(undefined4 *)(iVar5 + 0x10) = 0;
        return;
      }
      if ((((*(byte *)(iVar5 + DAT_0204e910) & 1) != 0) &&
          (bVar1 = *(byte *)(*DAT_0204e908 + DAT_0204e918),
          bVar1 == (bVar1 & *(byte *)(*DAT_0204e908 + DAT_0204e914)))) &&
         (*(int *)(iVar5 + 0xc) == 0x18)) {
        *(undefined4 *)(iVar5 + 0x10) = 0;
        return;
      }
      break;
    case 7:
      *(byte *)(iVar4 + DAT_0204e914) =
           *(byte *)(iVar4 + DAT_0204e914) | (byte)(1 << (param_1 & 0xff));
      iVar7 = *DAT_0204e908;
      if (*(byte *)(iVar7 + DAT_0204e918) ==
          (*(byte *)(iVar7 + DAT_0204e918) & *(byte *)(iVar7 + iVar5))) {
        *(undefined4 *)(iVar7 + 0x10) = 0;
        return;
      }
      break;
    case 9:
      *(byte *)(iVar4 + DAT_0204e91c) =
           *(byte *)(iVar4 + DAT_0204e91c) | (byte)(1 << (param_1 & 0xff));
      return;
    case 10:
      bVar2 = true;
      if ((*(byte *)(iVar4 + DAT_0204e910) & 1) == 0) {
        if (((*(byte *)(iVar4 + 0x8b) & 4) != 0) && (((uint)*param_3 << 0x18) >> 0x1c == 0)) {
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        func_02007d50(param_1,1);
        return;
      }
      func_02007d50(param_1,0);
      return;
    case 0xc:
      *(undefined4 *)(iVar4 + 0x10) = 0;
      return;
    case 0xe:
      uVar8 = 1 << (param_1 & 0xff);
      bVar1 = *(byte *)(iVar4 + DAT_0204e918);
      if ((bVar1 & uVar8) == 0) {
        *(byte *)(iVar4 + DAT_0204e918) = bVar1 | (byte)uVar8;
        *(char *)(*DAT_0204e908 + DAT_0204e924) = *(char *)(*DAT_0204e908 + DAT_0204e924) + '\x01';
      }
    }
  }
  return;
}

