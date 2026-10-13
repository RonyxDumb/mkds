/* Decompiled C draft; module arm9; ROM address 0214ec18. No matching claim. */
#include "types.h"
#include "deps/0214ec18_TouchPanelFifoCallback.h"

void TouchPanelFifoCallback(undefined4 param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar7;
  undefined4 local_10;
  undefined4 uStack_c;
  uint uVar6;
  
  uVar2 = DAT_0214eecc;
  uVar6 = ((param_2 & 0x7f00) << 8) >> 0x10;
  if (param_3 != 0) {
    pcVar4 = (code *)(*(uint *)(DAT_0214eecc & 0xfffffffc) >> (DAT_0214eecc & 3) * 8 |
                     *(uint *)(DAT_0214eecc & 0xfffffffc) << (DAT_0214eecc & 3) * -8 + 0x20);
    *(ushort *)(DAT_0214eecc + 0x34) = *(ushort *)(DAT_0214eecc + 0x34) | (ushort)(1 << uVar6);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(uVar6,4,0);
      return;
    }
    return;
  }
  if (uVar6 == 0x10) {
    puVar1 = (ushort *)(DAT_0214eecc + 0x14);
    *(short *)(DAT_0214eecc + 0xc) = *(short *)(DAT_0214eecc + 0xc) + 1;
    if (*puVar1 <= *(ushort *)(uVar2 + 0xc)) {
      *(undefined2 *)(uVar2 + 0xc) = 0;
    }
    uVar2 = DAT_0214eecc;
    uVar6 = DAT_0214eecc + 0x10 & 3;
    uVar5 = *(uint *)(DAT_0214eecc + 0x10 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    local_10 = CONCAT22(*DAT_0214eed4,*DAT_0214eed0);
    iVar3 = uVar6 + (uint)*(ushort *)(DAT_0214eecc + 0xc) * 8;
    *(ushort *)(uVar6 + (uint)*(ushort *)(DAT_0214eecc + 0xc) * 8) =
         (ushort)((uint)(local_10 << 0x14) >> 0x14);
    *(ushort *)(iVar3 + 2) = (ushort)((uint)local_10 >> 8) >> 4;
    *(ushort *)(iVar3 + 4) = (ushort)((uint)(local_10 << 7) >> 0x1f);
    *(ushort *)(iVar3 + 6) = (ushort)((uint)(local_10 << 5) >> 0x1e);
    pcVar4 = (code *)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(0x10,0,*(ushort *)(uVar2 + 0xc) & 0xff);
      return;
    }
    return;
  }
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  switch(param_2 & 0xff) {
  case 0:
    if (uVar6 == 0) {
      uStack_c = CONCAT22(*DAT_0214eed4,*DAT_0214eed0);
      *(undefined2 *)(DAT_0214eecc + 0x32) = 0;
      *(ushort *)(uVar2 + 4) = (ushort)((uint)(uStack_c << 0x14) >> 0x14);
      *(ushort *)(uVar2 + 6) = (ushort)((uint)uStack_c >> 8) >> 4;
      *(ushort *)(uVar2 + 8) = (ushort)((uint)(uStack_c << 7) >> 0x1f);
      *(ushort *)(uVar2 + 10) = (ushort)((uint)(uStack_c << 5) >> 0x1e);
    }
    else if (uVar6 == 1) {
      *(undefined2 *)(DAT_0214eecc + 0x32) = 2;
    }
    else if (uVar6 == 2) {
      *(undefined2 *)(DAT_0214eecc + 0x32) = 0;
    }
    pcVar4 = (code *)(*(uint *)(DAT_0214eecc & 0xfffffffc) >> (DAT_0214eecc & 3) * 8 |
                     *(uint *)(DAT_0214eecc & 0xfffffffc) << (DAT_0214eecc & 3) * -8 + 0x20);
    *(ushort *)(DAT_0214eecc + 0x36) = *(ushort *)(DAT_0214eecc + 0x36) & ~(ushort)(1 << uVar6);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(uVar6,0,0);
      return;
    }
    return;
  case 1:
  default:
    Os_Terminate();
    return;
  case 2:
    uVar7 = 1;
    break;
  case 3:
    uVar7 = 2;
    break;
  case 4:
    uVar7 = 3;
  }
  pcVar4 = (code *)(*(uint *)(DAT_0214eecc & 0xfffffffc) >> (DAT_0214eecc & 3) * 8 |
                   *(uint *)(DAT_0214eecc & 0xfffffffc) << (DAT_0214eecc & 3) * -8 + 0x20);
  *(ushort *)(DAT_0214eecc + 0x34) = *(ushort *)(DAT_0214eecc + 0x34) | (ushort)(1 << uVar6);
  *(ushort *)(uVar2 + 0x36) = *(ushort *)(uVar2 + 0x36) & ~(ushort)(1 << uVar6);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(uVar6,uVar7,0);
    return;
  }
  return;
}

