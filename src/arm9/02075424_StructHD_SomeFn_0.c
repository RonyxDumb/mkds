/* Decompiled C draft; module arm9; ROM address 02075424. No matching claim. */
#include "types.h"
#include "deps/02075424_StructHD_SomeFn_0.h"

void StructHD_SomeFn_0(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = param_1 + 0x218 & 3;
  uVar2 = *(uint *)(param_1 + 0x218 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  StructHD_SomeFn_1();
  *(short *)(param_1 + 0x23c) = *(short *)(param_1 + 0x23c) + 1;
  uVar3 = param_1 + 0x218 & 3;
  uVar2 = *(uint *)(param_1 + 0x218 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (*(short *)(param_1 + 0x23c) != *(short *)(uVar3 + 0x46)) {
    return;
  }
  uVar1 = *(ushort *)(uVar3 + 0x48);
  if (uVar1 == 0xffff) {
    iVar5 = 0;
  }
  else {
    uVar3 = (*(uint *)(uRam02075634 & 0xfffffffc) >> (uRam02075634 & 3) * 8 |
            *(uint *)(uRam02075634 & 0xfffffffc) << (uRam02075634 & 3) * -8 + 0x20) + 0x7c;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar5 = (uint)uVar1 * 0x4c + (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  }
  if (iVar5 == 0) {
    *(undefined4 *)
     ((*(uint *)(uRam02075638 & 0xfffffffc) >> (uRam02075638 & 3) * 8 |
      *(uint *)(uRam02075638 & 0xfffffffc) << (uRam02075638 & 3) * -8 + 0x20) + 0x4d0) = 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x23c) = 0;
    *(int *)(param_1 + 0x218) = iVar5;
    *(undefined4 *)(param_1 + 0x244) = 0;
    *(undefined4 *)(param_1 + 0x240) = 0;
    if (*(short *)(iVar5 + 0x40) != -1) {
      StructVC_SomeFnLinkedRouteRelated(param_1 + 0x194,iVar5);
    }
    uVar3 = (*(uint *)(uRam0207563c & 0xfffffffc) >> (uRam0207563c & 3) * 8 |
            *(uint *)(uRam0207563c & 0xfffffffc) << (uRam0207563c & 3) * -8 + 0x20) + 0xc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 5) {
      SetSomeAwardModeProperty(*(char *)(iVar5 + 0x4b) != '\0');
    }
    *puRam02075640 = 1;
  }
  uVar3 = param_1 + 0x218 & 3;
  uVar2 = *(uint *)(param_1 + 0x218 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  if (param_1 !=
      (*(uint *)(uRam02075644 & 0xfffffffc) >> (uRam02075644 & 3) * 8 |
      *(uint *)(uRam02075644 & 0xfffffffc) << (uRam02075644 & 3) * -8 + 0x20)) {
    return;
  }
  uVar3 = param_1 + 0x24c & 3;
  uVar2 = *(uint *)(param_1 + 0x24c & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
    uVar2 = *(uint *)(uRam02075648 & 0xfffffffc) >> (uRam02075648 & 3) * 8 |
            *(uint *)(uRam02075648 & 0xfffffffc) << (uRam02075648 & 3) * -8 + 0x20;
    uVar3 = uVar2 + 0x218 & 3;
    uVar4 = *(uint *)(uVar2 + 0x218 & 0xfffffffc);
    uVar1 = *(ushort *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x48);
    if (uVar1 == 0xffff) {
      iVar5 = 0;
    }
    else {
      uVar3 = (*(uint *)(uRam02075634 & 0xfffffffc) >> (uRam02075634 & 3) * 8 |
              *(uint *)(uRam02075634 & 0xfffffffc) << (uRam02075634 & 3) * -8 + 0x20) + 0x7c;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = (uint)uVar1 * 0x4c + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    }
    if (iVar5 != 0) {
      *(undefined2 *)(uVar2 + 0x23c) = 0;
      *(int *)(uVar2 + 0x218) = iVar5;
      *(undefined4 *)(uVar2 + 0x244) = 0;
      *(undefined4 *)(uVar2 + 0x240) = 0;
      if (*(short *)(iVar5 + 0x40) != -1) {
        StructVC_SomeFnLinkedRouteRelated(uVar2 + 0x194,iVar5);
      }
      uVar3 = (*(uint *)(uRam0207563c & 0xfffffffc) >> (uRam0207563c & 3) * 8 |
              *(uint *)(uRam0207563c & 0xfffffffc) << (uRam0207563c & 3) * -8 + 0x20) + 0xc;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 5) {
        SetSomeAwardModeProperty(*(char *)(iVar5 + 0x4b) != '\0');
      }
      *puRam02075640 = 1;
      return;
    }
    *(undefined4 *)
     ((*(uint *)(uRam02075638 & 0xfffffffc) >> (uRam02075638 & 3) * 8 |
      *(uint *)(uRam02075638 & 0xfffffffc) << (uRam02075638 & 3) * -8 + 0x20) + 0x4d0) = 1;
    return;
  }
  return;
}

