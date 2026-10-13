/* Decompiled C draft; module arm9; ROM address 0205fa00. No matching claim. */
#include "types.h"
#include "deps/0205fa00_func_0205fa00.h"

void func_0205fa00(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *unaff_r6;
  ushort *unaff_r7;
  ushort uStack_48;
  ushort uStack_46;
  ushort uStack_44;
  ushort uStack_42;
  ushort uStack_40;
  ushort uStack_3e;
  ushort uStack_3c;
  undefined1 auStack_3a [20];
  byte bStack_26;
  
  uVar5 = *(uint *)(uRam0205fbb0 & 0xfffffffc) >> (uRam0205fbb0 & 3) * 8 |
          *(uint *)(uRam0205fbb0 & 0xfffffffc) << (uRam0205fbb0 & 3) * -8 + 0x20;
  if (param_1 == *(char *)(uVar5 + 0x62)) {
    return;
  }
  uVar5 = uVar5 + param_1 * 0x30 + 0x90;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  uVar5 = FindSomeOI_FriendCode_Index();
  if (uVar5 == 0xffffffff) {
    return;
  }
  GlobalZ_GetOI(uVar5 & 0xff,(int)(uintptr_t)(&uStack_48));
  if (-1 < (int)((uint)bStack_26 << 0x1f)) {
    StructOI_Initialize_from_thumb(&uStack_48);
  }
  uVar2 = (*(uint *)(uRam0205fbb0 & 0xfffffffc) >> (uRam0205fbb0 & 3) * 8 |
          *(uint *)(uRam0205fbb0 & 0xfffffffc) << (uRam0205fbb0 & 3) * -8 + 0x20) + param_1 * 0x30 +
          0x88;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(uVar2),(uint *)(void *)(auStack_3a),0x14);
  }
  if (param_3 == 0) {
    unaff_r6 = &uStack_46;
    unaff_r7 = &uStack_48;
  }
  else if (param_3 == 1) {
    unaff_r6 = &uStack_42;
    unaff_r7 = &uStack_44;
  }
  else if (param_3 == 2) {
    unaff_r7 = &uStack_40;
    unaff_r6 = &uStack_3e;
  }
  if (param_4 == 0) {
    if (*unaff_r7 < uRam0205fbb4) {
      *unaff_r7 = *unaff_r7 + 1;
    }
  }
  else if ((param_4 == 1) && (*unaff_r6 < uRam0205fbb4)) {
    *unaff_r6 = *unaff_r6 + 1;
  }
  uVar2 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar1 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  bStack_26 = bStack_26 & 0xfe | 1;
  uStack_3c = ((ushort)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8) |
              (ushort)(*(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) & 0x7f |
              (ushort)(((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xf) << 7) |
              (ushort)(((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x1f) << 0xb);
  GlobalZ_SetOI(uVar5 & 0xff,(undefined4)(uintptr_t)(&uStack_48));
  return;
}

