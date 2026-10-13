/* Decompiled C draft; module arm9; ROM address 0211c5ac. No matching claim. */
#include "types.h"
#include "deps/0211c5ac_func_0211c5ac.h"

void func_0211c5ac(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort local_18;
  ushort local_16;
  
  local_18 = 8;
  local_16 = 8;
  uVar4 = 0;
  do {
    func_0211c810(uVar4 & 0xffff,3);
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 8);
  iVar2 = func_0211d62c();
  if (iVar2 != 0) {
    iVar2 = *piRam0211c80c;
    if (*(int *)(iVar2 + 0x78) == 0) {
      func_0211d2f0(&local_18);
      func_0211c810(local_18,0);
      uVar4 = func_0211d62c();
      if (1 < uVar4) {
        func_0211d2f0(&local_16);
        if (local_18 == local_16) {
          do {
            func_0211d2f0(&local_16);
          } while (local_18 == local_16);
        }
        func_0211c810(local_16,1);
        return;
      }
    }
    else {
      iVar3 = func_0211d3f4(*(undefined4 *)(iVar2 + 0x8c));
      if (*(short *)(iVar2 + iVar3 * 2 + 0xb0) == 0) {
        if (*(short *)(*piRam0211c80c + *(int *)(*piRam0211c80c + 0x8c) * 2 + 0xb0) != 0) {
          func_0211d2f0(&local_18);
          piVar1 = piRam0211c80c;
          uVar4 = (uint)local_18;
          if (*(int *)(*piRam0211c80c + 0x8c) != *(int *)(*piRam0211c80c + uVar4 * 4 + 0x8c)) {
            do {
              func_0211d2f0(&local_18);
              uVar4 = (uint)local_18;
            } while (*(int *)(*piVar1 + 0x8c) != *(int *)(*piVar1 + uVar4 * 4 + 0x8c));
          }
          func_0211c810(uVar4,0);
          if (1 < *(ushort *)(*piRam0211c80c + *(int *)(*piRam0211c80c + 0x8c) * 2 + 0xb0)) {
            func_0211d2f0(&local_16);
            piVar1 = piRam0211c80c;
            while ((uVar4 = (uint)local_16,
                   *(int *)(*piVar1 + 0x8c) != *(int *)(*piVar1 + uVar4 * 4 + 0x8c) ||
                   (local_18 == uVar4))) {
              func_0211d2f0(&local_16);
            }
            func_0211c810(uVar4,1);
          }
        }
      }
      else {
        func_0211d2f0(&local_18);
        uVar4 = (uint)local_18;
        iVar2 = func_0211d3f4(*(undefined4 *)(*piRam0211c80c + 0x8c));
        piVar1 = piRam0211c80c;
        if (*(int *)(*piRam0211c80c + uVar4 * 4 + 0x8c) != iVar2) {
          do {
            func_0211d2f0(&local_18);
            uVar4 = (uint)local_18;
            iVar2 = func_0211d3f4(*(undefined4 *)(*piVar1 + 0x8c));
          } while (*(int *)(*piVar1 + uVar4 * 4 + 0x8c) != iVar2);
        }
        func_0211c810(uVar4,0);
        if (*(short *)(*piRam0211c80c + *(int *)(*piRam0211c80c + 0x8c) * 2 + 0xb0) != 0) {
          func_0211d2f0(&local_16);
          piVar1 = piRam0211c80c;
          uVar4 = (uint)local_16;
          if (*(int *)(*piRam0211c80c + 0x8c) != *(int *)(*piRam0211c80c + uVar4 * 4 + 0x8c)) {
            do {
              func_0211d2f0(&local_16);
              uVar4 = (uint)local_16;
            } while (*(int *)(*piVar1 + 0x8c) != *(int *)(*piVar1 + uVar4 * 4 + 0x8c));
          }
          func_0211c810(uVar4,1);
          return;
        }
        iVar2 = func_0211d3f4();
        if (1 < *(ushort *)(*piRam0211c80c + iVar2 * 2 + 0xb0)) {
          func_0211d2f0(&local_16);
          piVar1 = piRam0211c80c;
          while( true ) {
            uVar4 = (uint)local_16;
            iVar2 = func_0211d3f4(*(undefined4 *)(*piVar1 + 0x8c));
            if ((*(int *)(*piVar1 + uVar4 * 4 + 0x8c) == iVar2) && (local_18 != uVar4)) break;
            func_0211d2f0(&local_16);
          }
          func_0211c810(uVar4,1);
          return;
        }
      }
    }
  }
  return;
}

