/* Decompiled C draft; module arm9; ROM address 0211d174. No matching claim. */
#include "types.h"
#include "deps/0211d174_func_0211d174.h"

void func_0211d174(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  ushort local_1c [4];
  
  local_1c[0] = 8;
  if (param_2 != *(int *)(*piRam0211d2dc + param_1 * 4 + 0x8c)) {
    iVar1 = func_0211d44c();
    if (iVar1 == 0) {
      piVar5 = (int *)*puRam0211d2e0;
      if (*piVar5 == 2) {
        uVar2 = (uint)*(ushort *)((int)piVar5 + iRam0211d2e4);
      }
      else {
        uVar2 = 0;
      }
      if (param_1 == *(ushort *)((int)piVar5 + iRam0211d2e8 + ((uVar2 << 0x10) >> 0xd))) {
        NNSi_MaybeSndPlayerStartSeq(uRam0211d2ec,0,0x16);
        return;
      }
    }
    else {
      func_0211d428(param_1,param_2);
      iVar1 = func_0211d40c(param_1);
      if (iVar1 == 0) {
        *(short *)(*piRam0211d2dc + 0xb0 + param_2 * 2) =
             *(short *)(*piRam0211d2dc + 0xb0 + param_2 * 2) + 1;
        iVar1 = func_0211d3f4(param_2);
        *(short *)(*piRam0211d2dc + 0xb0 + iVar1 * 2) =
             *(short *)(*piRam0211d2dc + 0xb0 + iVar1 * 2) + -1;
      }
      else {
        *(short *)(*piRam0211d2dc + 0xac + param_2 * 2) =
             *(short *)(*piRam0211d2dc + 0xac + param_2 * 2) + 1;
        iVar1 = func_0211d3f4(param_2);
        *(short *)(*piRam0211d2dc + 0xac + iVar1 * 2) =
             *(short *)(*piRam0211d2dc + 0xac + iVar1 * 2) + -1;
      }
      iVar1 = func_0211d3a8();
      if ((iVar1 != 2) && (*(short *)(*piRam0211d2dc + iVar1 * 2 + 0xb0) != 0)) {
        func_0211d2f0(local_1c);
        piVar5 = piRam0211d2dc;
        iVar3 = *(int *)(*piRam0211d2dc + (uint)local_1c[0] * 4 + 0x8c);
        while (iVar1 != iVar3) {
          func_0211d2f0(local_1c);
          iVar3 = *(int *)(*piVar5 + (uint)local_1c[0] * 4 + 0x8c);
        }
        uVar4 = func_0211d3f4(iVar1);
        func_0211d174(local_1c[0],uVar4);
      }
      piVar5 = (int *)*puRam0211d2e0;
      if (*piVar5 == 2) {
        uVar2 = (uint)*(ushort *)((int)piVar5 + iRam0211d2e4);
      }
      else {
        uVar2 = 0;
      }
      if (param_1 == *(ushort *)((int)piVar5 + iRam0211d2e8 + ((uVar2 << 0x10) >> 0xd))) {
        iVar3 = *piRam0211d2dc;
        iVar1 = *(int *)(iVar3 + param_1 * 4 + 0x8c);
        if (iVar1 == 0) {
          *(undefined2 *)(iVar3 + 0x54) = 6;
        }
        else if (iVar1 == 1) {
          *(undefined2 *)(iVar3 + 0x56) = 6;
        }
        NNSi_MaybeSndPlayerStartSeq(uRam0211d2ec,0,4);
      }
    }
  }
  return;
}

