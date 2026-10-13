/* Decompiled C draft; module arm9; ROM address 020787f4. No matching claim. */
#include "types.h"
#include "deps/020787f4_func_020787f4.h"

void func_020787f4(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  func_02011034();
  iVar2 = *piRam0207890c;
  iVar3 = piRam0207890c[1];
  local_4c = piRam0207890c[2];
  local_54 = iVar2;
  local_50 = iVar3;
  lVar7 = Multiply64(local_4c,local_4c >> 0x1f,local_4c,local_4c >> 0x1f);
  lVar8 = Multiply64(iVar2,iVar2 >> 0x1f,iVar2,iVar2 >> 0x1f);
  lVar9 = Multiply64(iVar3,iVar3 >> 0x1f,iVar3,iVar3 >> 0x1f);
  lVar7 = lVar7 + lVar8 + lVar9;
  if ((int)(uint)((uint)lVar7 < 0x10) <= (int)((ulonglong)lVar7 >> 0x20)) {
    Vector3_MaybeNormalize(&local_54,&local_54);
  }
  func_02010fac(0,(int)(short)local_54,(int)(short)local_50,(int)(short)local_4c);
  uVar5 = (uint)*puRam02078910;
  func_02010f98(0,(uVar5 << 10 | uVar5 | uVar5 << 5) & 0xffff);
  func_02078934(0);
  local_30 = *puRam02078914;
  uStack_2c = puRam02078914[1];
  local_28 = puRam02078914[2];
  local_24 = *puRam02078918;
  local_1c = puRam02078918[2];
  local_20 = puRam02078918[1] + param_2;
  VecFx32_Subtract(&local_24,puRam0207891c,auStack_3c);
  VecFx32_CrossProduct(&local_30,auStack_3c,&local_48);
  puVar1 = puRam02078920;
  uVar4 = puRam0207891c[1];
  puVar6 = puRam0207891c + 2;
  *puRam02078920 = *puRam0207891c;
  puVar1[1] = uVar4;
  puVar1[2] = *puVar6;
  puVar1 = puRam02078924;
  *puRam02078924 = local_48;
  puVar1[1] = uStack_44;
  puVar1[2] = local_40;
  puVar1 = puRam02078928;
  *puRam02078928 = local_24;
  puVar1[1] = local_20;
  puVar1[2] = local_1c;
  G3i_LookAt_(puRam0207891c,&local_48,&local_24,0,uRam0207892c);
  *(uint *)(iRam02078930 + 0x7c) = *(uint *)(iRam02078930 + 0x7c) & 0xffffff17;
  func_02011034();
  return;
}

