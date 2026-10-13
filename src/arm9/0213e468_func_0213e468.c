/* Decompiled C draft; module arm9; ROM address 0213e468. No matching claim. */
#include "types.h"
#include "deps/0213e468_func_0213e468.h"

/* WARNING: Removing unreachable block (ram,0x0213eab4) */
/* WARNING: Removing unreachable block (ram,0x0213ea64) */
/* WARNING: Removing unreachable block (ram,0x0213eafc) */
/* WARNING: Removing unreachable block (ram,0x0213ec98) */
/* WARNING: Removing unreachable block (ram,0x0213ec48) */
/* WARNING: Removing unreachable block (ram,0x0213ec7c) */
/* WARNING: Removing unreachable block (ram,0x0213eb4c) */
/* WARNING: Removing unreachable block (ram,0x0213ebe8) */
/* WARNING: Removing unreachable block (ram,0x0213eb10) */
/* WARNING: Removing unreachable block (ram,0x0213ea98) */
/* WARNING: Removing unreachable block (ram,0x0213e63c) */
/* WARNING: Removing unreachable block (ram,0x0213eb60) */
/* WARNING: Removing unreachable block (ram,0x0213ec24) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ushort * func_0213e468(int param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  uint local_18;
  uint local_14;
  
  uVar4 = CONCAT13(uStack_19,0x101) & 0xff00ff00;
  local_18 = 0;
  local_14 = 0;
  uStack_1b = (undefined1)(uVar4 >> 8);
  uVar2 = *(ushort *)(param_1 + 2);
  uVar3 = (uint)uVar2;
  puVar5 = (ushort *)(param_1 + 2);
  if (uVar3 == 0x25) {
    uStack_1a = (undefined1)uVar2;
    uStack_19 = (undefined1)(uVar2 >> 8);
    *param_3 = 0x1010101;
    param_3[1] = CONCAT13(uStack_19,CONCAT12(uStack_1a,(short)uVar4));
    param_3[2] = 0;
    param_3[3] = 0;
    return (ushort *)(param_1 + 4);
  }
  do {
    bVar1 = true;
    if (uVar3 < 0x2c) {
      if ((uVar3 < 0x2b) &&
         (((0x23 < uVar3 || (uVar3 < 0x20)) || ((uVar3 != 0x20 && (uVar3 != 0x23)))))) {
LAB_0213e6d4:
        bVar1 = false;
      }
    }
    else if (((0x30 < uVar3) || (uVar3 < 0x2d)) || ((uVar3 != 0x2d && (uVar3 != 0x30))))
    goto LAB_0213e6d4;
    if (!bVar1) break;
    puVar5 = puVar5 + 1;
    uVar3 = (uint)*puVar5;
  } while( true );
  if (uVar3 == 0x2a) {
    *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) + 4;
    uVar4 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) - 4;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    local_18 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    if ((int)local_18 < 0) {
      local_18 = -local_18;
    }
    puVar5 = puVar5 + 1;
    uVar3 = (uint)*puVar5;
  }
  else {
    while( true ) {
      if (uVar3 < 0x80) {
        uVar2 = *(ushort *)(DAT_0213ecec + uVar3 * 2) & 8;
      }
      else {
        uVar2 = 0;
      }
      if (uVar2 == 0) break;
      local_18 = local_18 * 10 + (uVar3 - 0x30);
      puVar5 = puVar5 + 1;
      uVar3 = (uint)*puVar5;
    }
  }
  if (DAT_0213ecf0 < (int)local_18) {
    uStack_1a = (undefined1)DAT_0213ecf4;
    uStack_19 = (undefined1)((uint)DAT_0213ecf4 >> 8);
    *param_3 = 0x1010101;
    param_3[1] = (uint)CONCAT12(uStack_19,CONCAT11(uStack_1a,uStack_1b)) << 8;
    param_3[2] = local_18;
    param_3[3] = 0;
    return puVar5 + 1;
  }
  puVar6 = puVar5;
  if (uVar3 == 0x2e) {
    puVar6 = puVar5 + 1;
    uVar3 = (uint)*puVar6;
    if (uVar3 == 0x2a) {
      *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                 *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) + 4;
      uVar4 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) - 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      local_14 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      puVar6 = puVar5 + 2;
      uVar3 = (uint)*puVar6;
    }
    else {
      while( true ) {
        if (uVar3 < 0x80) {
          uVar2 = *(ushort *)(DAT_0213ecec + uVar3 * 2) & 8;
        }
        else {
          uVar2 = 0;
        }
        if (uVar2 == 0) break;
        local_14 = local_14 * 10 + (uVar3 - 0x30);
        puVar6 = puVar6 + 1;
        uVar3 = (uint)*puVar6;
      }
    }
  }
  bVar1 = true;
  if (uVar3 != 0x4c) {
    if (uVar3 == 0x68) {
      if (puVar6[1] == 0x68) {
        puVar6 = puVar6 + 1;
        uVar3 = (uint)*puVar6;
      }
    }
    else if (uVar3 == 0x6c) {
      if (puVar6[1] == 0x6c) {
        puVar6 = puVar6 + 1;
        uVar3 = (uint)*puVar6;
      }
    }
    else {
      bVar1 = false;
    }
  }
  if (bVar1) {
    puVar6 = puVar6 + 1;
    uVar3 = (uint)*puVar6;
  }
  if (uVar3 < 100) {
    if ((((0x62 < uVar3) || (0x47 < uVar3)) || (uVar3 < 0x45)) ||
       (((uVar3 == 0x45 || (uVar3 == 0x46)) || (uVar3 != 0x47)))) goto switchD_0213e9fc_default;
LAB_0213eb1c:
    if (local_14 == 0) {
      local_14 = 1;
    }
  }
  else {
    switch(uVar3) {
    case 100:
      break;
    case 0x65:
      break;
    case 0x66:
      break;
    case 0x67:
      goto LAB_0213eb1c;
    case 0x68:
      break;
    case 0x69:
      break;
    case 0x6a:
      break;
    case 0x6b:
      break;
    case 0x6c:
      break;
    case 0x6d:
      break;
    case 0x6e:
      break;
    case 0x6f:
      break;
    case 0x70:
      local_14 = 8;
      break;
    case 0x71:
      break;
    case 0x72:
      break;
    case 0x73:
      break;
    case 0x74:
      break;
    case 0x75:
    }
  }
switchD_0213e9fc_default:
  *param_3 = 0x1010101;
  param_3[1] = CONCAT13(uStack_19,0x101) & 0xff00ff00;
  param_3[2] = local_18;
  param_3[3] = local_14;
  return puVar6 + 1;
}

