/* Decompiled C draft; module arm9; ROM address 0200c568. No matching claim. */
#include "types.h"
#include "deps/0200c568_MaybeDebuggerOrAddonCode_from_thumb.h"

undefined4 MaybeDebuggerOrAddonCode_from_thumb(void)

{
  undefined4 uVar1;
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [8];
  
  uVar1 = 1;
  if (*puRam0200c60c == uRam0200c610) {
    return 0;
  }
  if ((int)((uint)*(byte *)((int)puRam0200c60c + 5) << 0x1e) < 0) {
    return 0;
  }
  func_0200c4c0(*(undefined2 *)(iRam0200c614 + 2),(uint *)(void *)(auStack_18));
  ReadSomeExmemcntData_from_thumb((int *)(void *)(auStack_10));
  if (((*(char *)(iRam0200c618 + 0xb2) != -0x6a) ||
      (*puRam0200c60c == *(ushort *)(iRam0200c618 + 0xbe))) &&
     ((*(char *)(iRam0200c618 + 0xb2) == -0x6a || (*puRam0200c60c == *puRam0200c61c)))) {
    if ((*(int *)(puRam0200c60c + 4) == *(int *)(iRam0200c618 + 0xac)) ||
       ((*(byte *)((int)puRam0200c60c + 5) & 1) == 0)) goto LAB_0200c5f2;
  }
  *(byte *)((int)puRam0200c60c + 5) = *(byte *)((int)puRam0200c60c + 5) | 2;
  uVar1 = 0;
LAB_0200c5f2:
  func_0200c508((int *)(void *)(auStack_10));
  func_0200c4a4(*(undefined2 *)(iRam0200c614 + 2),(int *)(void *)(auStack_18));
  return uVar1;
}

