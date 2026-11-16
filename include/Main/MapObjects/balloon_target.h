#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

#define BALLOON_TARGET_NO_KART_FRAMES 0x1e

void StartBalloonWithoutKart(Balloon *balloon, Vec3 *position);
void SetBalloonTargetPosAndVelocity(Balloon *balloon, Vec3 *targetPos, Vec3 *targetVelocity);
