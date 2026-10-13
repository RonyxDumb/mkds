/* Decompiled C draft; module arm9; ROM address 02078580. No matching claim. */
#include "types.h"
#include "deps/02078580_func_02078580.h"

void func_02078580(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  undefined1 auStack_b4 [36];
  undefined1 auStack_90 [36];
  undefined1 auStack_6c [36];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  *(undefined4 *)(iRam020787d4 + 0x20) = uRam020787d0;
  local_3c = *puRam020787d8;
  local_38 = puRam020787d8[1];
  local_34 = puRam020787d8[2];
  local_c0 = func_021488e8(*puRam020787dc,*(undefined4 *)(param_2 + 8));
  iVar1 = (int)(uint)*(ushort *)(param_2 + 0x16) >> 4;
  local_bc = local_c0;
  local_b8 = local_c0;
  MTX_RotY33__from_thumb
            ((undefined4 *)(void *)(auStack_b4),(int)*(short *)(iRam020787e0 + iVar1 * 4),
             (int)*(short *)(iRam020787e0 + (iVar1 * 2 + 1) * 2));
  iVar1 = (int)((uint)*puRam020787e4 + (uint)*(ushort *)(param_2 + 0x1a) & 0xffff) >> 4;
  MTX_RotX33__from_thumb
            ((undefined4 *)(void *)(auStack_90),(int)*(short *)(iRam020787e0 + iVar1 * 4),
             (int)*(short *)(iRam020787e0 + (iVar1 * 2 + 1) * 2));
  MTX_Concat33((uint)(uintptr_t)(auStack_b4),(uint *)(void *)(auStack_90),(uint *)(void *)(auStack_b4));
  if (param_1[8] == 0) {
    Matrix4x3_Identity((undefined4 *)(void *)(auStack_6c));
  }
  else {
    func_02146ce0((undefined4 *)(void *)(auStack_b4),(undefined4 *)(void *)(auStack_6c));
    local_48 = local_3c;
    uStack_44 = local_38;
    local_40 = local_34;
    func_02147914(auStack_6c,auStack_6c,local_c0,local_bc,local_b8);
  }
  func_02010fe4(&local_c0);
  func_0201100c(&local_3c);
  asm_MI_Copy36B((undefined4 *)(void *)(auStack_90),(undefined4 *)(uintptr_t)(uRam020787e8));
  *(uint *)(iRam020787d4 + 0x7c) = *(uint *)(iRam020787d4 + 0x7c) & 0xffffff5b;
  func_02011034();
  if (*(int *)(*piRam020787ec + iRam020787f0) != 0) {
    func_01ff8cf0();
  }
  asm_MI_Copy36B((undefined4 *)(void *)(auStack_b4),(undefined4 *)(uintptr_t)(uRam020787e8));
  *(uint *)(iRam020787d4 + 0x7c) = *(uint *)(iRam020787d4 + 0x7c) & 0xffffff5b;
  func_0201100c(&local_3c);
  func_02011034();
  if ((*param_1 != -1) && (param_1[1] != -1)) {
    func_02078934(param_3);
    iVar1 = param_1[7];
    if (iVar1 != 0) {
      if (param_3 == 0) {
        *(undefined4 *)(iVar1 + 0x54) = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x54) = 1;
      }
      func_0207adf8(param_1[7]);
    }
    if (param_1[5] != 0) {
      if (param_3 == 0) {
        func_02084f20();
      }
      else {
        func_02084f68();
      }
      func_01ff8cf0((uint *)(uintptr_t)(param_1[5]));
    }
    if (param_1[6] != 0) {
      uVar2 = 0;
      do {
        if (uVar2 < 2) {
          iVar3 = *(int *)(param_1[8] + 0x10);
          iVar1 = iVar3 >> 0x1f;
          uVar4 = Multiply64(local_c0,(int)local_c0 >> 0x1f,iVar3,iVar1);
          local_24 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
          uVar4 = Multiply64(local_bc,(int)local_bc >> 0x1f,iVar3,iVar1);
          local_20 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
          uVar4 = Multiply64(local_b8,(int)local_b8 >> 0x1f,iVar3,iVar1);
          local_1c = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
        }
        else {
          local_24 = local_c0;
          local_20 = local_bc;
          local_1c = local_b8;
        }
        if ((uVar2 != 1) || (*(int *)(param_1[8] + 0x14) != 0)) {
          iVar1 = param_1[8] + 0x14 + uVar2 * 0xc;
          local_30 = *(int *)(param_1[8] + 0x14 + uVar2 * 0xc) >> 4;
          local_2c = *(int *)(iVar1 + 4) >> 4;
          local_28 = *(int *)(iVar1 + 8) >> 4;
          func_02147288((uint)(uintptr_t)(&local_30),(uint)(uintptr_t)(auStack_6c),&local_3c);
          func_02010fe4(&local_24);
          func_0201100c(&local_3c);
          func_02011034();
          if (param_3 == 0) {
            func_02084f20(param_1[6]);
          }
          else {
            func_02084f68(param_1[6]);
          }
          func_01ff8cf0(param_1[6]);
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 4);
    }
    if (param_1[4] != 0) {
      func_02147288(param_1[8] + 0x44 + *param_1 * 0xc,auStack_6c,&local_3c);
      func_0201100c(&local_3c);
      func_02011034();
      if (param_3 == 0) {
        func_02084f20(param_1[4]);
      }
      else {
        func_02084f68(param_1[4]);
      }
      func_01ff8cf0(param_1[4]);
    }
  }
  return;
}

