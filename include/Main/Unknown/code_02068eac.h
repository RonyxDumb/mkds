#pragma once

#include "types.h"

typedef struct Kart Kart;

BOOL StructMQRacerEntry_HasFlags0x60(Kart *kart);
s32 StructMQRacerEntry_SomeFn_35(Kart *kart, s32 a);
void StructMQRacerEntry_SomeFn_34(Kart *kart);
void driver_startSlipstream(Kart *kart);
void driver_updateGessoInk(Kart *kart);
void driver_startGessoInk(Kart *kart, u32 orthoQuadCount);
void driver_updateKillerMode(Kart *kart);
void driver_startKillerMode(Kart *kart);
void driver_updateTeresaEffect(Kart *kart);
void driver_startTeresaEffect(Kart *kart);
void driver_startStarInvincibility(Kart *kart);
void driver_startShroomBoost(Kart *kart);
void driver_invokeThunder(Kart *kart);
void driver_resetScaleEffects(Kart *kart);
void driver_updateDossunFlatEffect(Kart *kart);
BOOL driver_startDossunFlatEffect(Kart *kart);
