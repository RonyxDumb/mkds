#pragma once

#include "types.h"

typedef struct Kart Kart;

// Frames Kart.mCourseHitTimer runs after a course hit.
#define KART_COURSE_HIT_TIMER_FRAMES 3

void CollideKartWithCourse(Kart *kart, Vec3 *groundNormal);
