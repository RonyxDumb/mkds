#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

void StartBalloonWithoutKart(Balloon *balloon, Vec3 *position);
void SetBalloonTargetPosAndVelocity(Balloon *balloon, Vec3 *targetPos, Vec3 *targetVelocity);
