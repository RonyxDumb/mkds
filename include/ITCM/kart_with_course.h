#pragma once

#include "types.h"

typedef struct Kart Kart;

// Value Kart.mCourseHitTimer is set to on a course hit; it counts down by one on each step without course contact.
#define KART_COURSE_HIT_TIMER_FRAMES 3

void CollideKartWithCourse(Kart *kart, Vec3 *groundNormal);
