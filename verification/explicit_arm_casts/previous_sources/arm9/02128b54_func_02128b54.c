/* Decompiled C draft; module arm9; ROM address 02128b54. No matching claim. */
#include "types.h"
#include "deps/02128b54_func_02128b54.h"

void func_02128b54(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_28 [20];
  
  if (*(int *)(*piRam02128bcc + 4) == 1) {
    iVar1 = GetClampedString10LengthForFontIndex0_from_thumb(*piRam02128bcc + 0x44,auStack_28);
    iVar3 = 6;
    if (4 < iVar1) {
      iVar3 = 10 - iVar1;
    }
    iVar1 = 0;
    pbVar2 = pbRam02128bd0;
    do {
      iVar4 = 0;
      iVar5 = iVar4;
      do {
        if ((iVar1 < 6 - iVar3) || (*(short *)(*piRam02128bcc + 0x70) == 0xc)) {
          *(undefined4 *)(*(int *)(*piRam02128bcc + iVar4 + 0x7c) + (uint)*pbVar2 * 0x40) = 0;
        }
        else {
          *(undefined4 *)(*(int *)(*piRam02128bcc + iVar4 + 0x7c) + (uint)*pbVar2 * 0x40) = 1;
        }
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      pbVar2 = pbVar2 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
  }
  return;
}

