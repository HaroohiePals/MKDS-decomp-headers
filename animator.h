#pragma once

typedef enum
{
    ANIM_LOOP_MODE_STOP,
    ANIM_LOOP_MODE_INFINITE_LOOP,
    ANIM_LOOP_MODE_COUNTED_LOOP
} AnimLoopMode;

typedef struct
{
    u16 loopMode;
    u16 hasEnded;
    fx32 animLength;
    fx32 speed;
    fx32 progress;
    u16 loopIteration;
    u16 loopCount;
} anim_animator_t;

void anim_initAnimatorLoop(anim_animator_t* animator, fx32 animLength);
void anim_initAnimator(anim_animator_t* animator, fx32 animLength, u16 loop);
void anim_updateAnimator(anim_animator_t* animator);
