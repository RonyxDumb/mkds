/* Decompiled C draft; module arm9_ov000; ROM address 021ad0a4. No matching claim. */
#include "types.h"
#include "deps/021ad0a4_FUN_021ad0a4.h"

int FUN_021ad0a4(char *param_1,uint param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char cVar7;
  ushort *puVar8;
  char *pcVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int local_58;
  uint local_54;
  ushort local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_46;
  char local_44;
  char local_43 [47];
  
  local_50 = (ushort)(param_3 >> 8) | (ushort)(param_3 << 8);
  if (param_2 == 1) {
    local_4e = 1;
  }
  else {
    local_4e = (undefined2)DAT_021ad234;
  }
  local_4c = (undefined2)DAT_021ad238;
  local_4a = 0;
  local_48 = 0;
  local_46 = 0;
  pcVar9 = &local_44;
  pcVar5 = local_43;
  local_54 = 0;
  cVar7 = *param_1;
  param_1 = param_1 + 1;
  if (cVar7 != '\0') {
    do {
      if (cVar7 == '.') {
        *pcVar9 = (char)local_54;
        local_54 = 0;
        pcVar9 = pcVar5;
      }
      else {
        if (0x3b < (int)pcVar5 - (int)&local_50) {
          return -1;
        }
        *pcVar5 = cVar7;
        local_54 = local_54 + 1;
      }
      pcVar5 = pcVar5 + 1;
      cVar7 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar7 != '\0');
  }
  *pcVar9 = (char)local_54;
  *pcVar5 = '\0';
  pcVar5[1] = (char)(param_2 >> 8);
  pcVar5[2] = (char)param_2;
  pcVar5[3] = '\0';
  pcVar5[4] = '\x01';
  FUN_021adbf4((undefined4)(uintptr_t)(&local_50),(undefined4)(uintptr_t)(pcVar5 + (5 - (int)&local_50)));
  uVar11 = func_0x0200f5ac();
  local_58 = -1;
  iVar10 = 0;
  do {
    while( true ) {
      iVar4 = (*(code *)*DAT_021ad23c)();
      if (((iVar4 == 0) || (iVar10 != 0)) ||
         (uVar12 = func_0x0200f5ac(),
         0xe < (int)(((uint)uVar12 >> 0x10 | (int)((ulonglong)uVar12 >> 0x20) << 0x10) -
                    ((uint)uVar11 >> 0x10 | (int)((ulonglong)uVar11 >> 0x20) << 0x10)))) {
        return iVar10;
      }
      iVar4 = FUN_021adbac();
      if (iVar4 != 0) break;
      FUN_021b04d4();
    }
    puVar1 = (ushort *)FUN_021adf78(&local_54);
    iVar4 = iVar10;
    if (((0xc < local_54) && (param_3 == ((int)(uint)*puVar1 >> 8 | (*puVar1 & 0xff) << 8))) &&
       ((iVar4 = local_58, (*(byte *)((int)puVar1 + 3) & 0xf) != 3 &&
        (iVar4 = iVar10, (*(byte *)((int)puVar1 + 3) & 0xf) == 0)))) {
      puVar8 = (ushort *)((int)puVar1 + local_54);
      puVar2 = puVar1 + 6;
      for (uVar6 = (uint)CONCAT11((char)puVar1[2],*(undefined1 *)((int)puVar1 + 5)); uVar6 != 0;
          uVar6 = uVar6 - 1) {
        iVar4 = FUN_021ad240();
        puVar2 = (ushort *)(iVar4 + 4);
      }
      while (iVar4 = iVar10, puVar2 < puVar8) {
        puVar3 = (undefined1 *)FUN_021ad240();
        uVar6 = (uint)CONCAT11(puVar3[8],puVar3[9]);
        if (param_2 == CONCAT11(*puVar3,puVar3[1])) {
          iVar4 = CONCAT22(CONCAT11(puVar3[uVar6 + 6],puVar3[uVar6 + 7]),
                           CONCAT11(puVar3[uVar6 + 8],puVar3[uVar6 + 9]));
          break;
        }
        puVar2 = (ushort *)(puVar3 + uVar6 + 10);
      }
    }
    FUN_021adf00(local_54);
    iVar10 = iVar4;
  } while( true );
}

