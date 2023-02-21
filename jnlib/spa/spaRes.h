#pragma once

#define SPA_RES_EMITTER_EMITTER_SHAPE_POINT					0
#define SPA_RES_EMITTER_EMITTER_SHAPE_SPHERE				1
#define SPA_RES_EMITTER_EMITTER_SHAPE_CIRCLE				2
#define SPA_RES_EMITTER_EMITTER_SHAPE_CIRCLE_EVEN			3
#define SPA_RES_EMITTER_EMITTER_SHAPE_SPHERE_VOLUME			4
#define SPA_RES_EMITTER_EMITTER_SHAPE_CIRCLE_VOLUME			5
#define SPA_RES_EMITTER_EMITTER_SHAPE_CYLINDER				6
#define SPA_RES_EMITTER_EMITTER_SHAPE_CYLINDER_EVEN			7
#define SPA_RES_EMITTER_EMITTER_SHAPE_SEMISPHERE			8
#define SPA_RES_EMITTER_EMITTER_SHAPE_SEMISPHERE_VOLUME		9

#define SPA_RES_EMITTER_PARTICLE_TYPE_BILLBOARD				0
#define SPA_RES_EMITTER_PARTICLE_TYPE_DIR_BILLBOARD			1
#define SPA_RES_EMITTER_PARTICLE_TYPE_POLYGON				2
#define SPA_RES_EMITTER_PARTICLE_TYPE_DIR_POLYGON			3

#define SPA_RES_EMITTER_AXIS_DIR_Z				0
#define SPA_RES_EMITTER_AXIS_DIR_Y				1
#define SPA_RES_EMITTER_AXIS_DIR_X				2
#define SPA_RES_EMITTER_VIEW_DIRECTION_TYPE_CUSTOM			3

#define SPA_RES_EMITTER_QUAD_DIRECTION_XY					0
#define SPA_RES_EMITTER_QUAD_DIRECTION_XZ					1

#define SPA_RES_EMITTER_SCALE_MODE_UNIFORM					0
#define SPA_RES_EMITTER_SCALE_MODE_X						1
#define SPA_RES_EMITTER_SCALE_MODE_Y						2

typedef struct
{
    u32 emitterShape : 4;
    u32 particleType : 2;
    u32 axisDirType : 2;
    u32 hasScaleAnim : 1;
    u32 hasColorAnim : 1;
    u32 hasAlphaAnim : 1;
    u32 hasTexAnim : 1;
    u32 hasRandomParticleDeltaRotation : 1;
    u32 hasRandomParticleRotation : 1;
    u32 emitterIsOneTime : 1;
    u32 particlesFollowEmitter : 1;
    u32 hasChildParticles : 1;
    u32 rotMtxMode : 2;
    u32 quadDirection : 1;
    u32 randomizeParticleProgressOffset : 1;
    u32 renderChildParticlesFirst : 1;
    u32 dontRenderMainParticles : 1;
    u32 relativePosAsRotOrigin : 1;
    u32 hasFieldGravity : 1;
    u32 hasFieldRandom : 1;
    u32 hasFieldMagnetic : 1;
    u32 hasFieldSpin : 1;
    u32 hasFieldCollision : 1;
    u32 hasFieldConvergence : 1;
    u32 useConstPolygonIdForMainParticles : 1;
    u32 useConstPolygonIdForChildParticles : 1;
} spa_res_emitter_flags_t;

typedef struct
{
    spa_res_emitter_flags_t flags;

    VecFx32 position;
    fx32 emissionCount;
    fx32 emitterRadius;
    fx32 emitterLength;
    VecFx16 emitterAxis;
    GXRgb color;
    fx32 particlePosVeloMag;
    fx32 particleAxisVeloMag;
    fx32 particleBaseScale;
    fx16 aspectRatio;
    u16 emissionStartTime;
    s16 minRotVelocity;
    s16 maxRotVelocity;
    u16 particleRotation;
    u16 padding1;
    u16 emissionTime;
    u16 particleLifetime;
    u8 particleScaleRandomness;
    u8 particleLifetimeRandomness;
    u8 particleVeloMagRandomness;
    u8 padding2;
    u8 emissionInterval;
    u8 particleAlpha;
    u8 airResistance;
    u8 textureId;

    u32 loopFrame : 8;
    u32 dirBillboardScale : 16;
    u32 texRepeatShiftS : 2;
    u32 texRepeatShiftT : 2;
    u32 scaleMode : 3;
    u32 centerDirPolygon : 1; //?

    u32 texFlipS : 1;
    u32 texFlipT : 1;
    u32 : 30;

    fx16 quadXOffset;
    fx16 quadYZOffset;
    union
    {
        u32 userDataU32;
        u16 userDataU16[2];
        u8 userDataU8[4];
    };
} spa_res_emitter_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_t) == 0x58);

typedef struct
{
    fx16 initialScale;
    fx16 intermediateScale;
    fx16 endingScale;
    u8 inCompletedTiming;
    u8 scaleOutStartTime;
    u16 loop : 1;
    u16 : 15;
    u16 padding;
} spa_res_emitter_scaleanim_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_scaleanim_t) == 0xC);

typedef struct
{
    GXRgb initialColor;
    GXRgb endingColor;
    u8 inCompletedTiming;
    u8 peakTiming;
    u8 outStartTiming;
    u8 field7;
    u16 isRandom : 1;
    u16 loop : 1;
    u16 interpolate : 1;
    u16 : 13;
    u16 padding;
} spa_res_emitter_coloranim_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_coloranim_t) == 0xC);

typedef struct
{
    u16 initialAlpha : 5;
    u16 peakAlpha : 5;
    u16 endingAlpha : 5;
    u16 : 1;
    u16 randomness : 8;
    u16 loop : 1;
    u16 : 7;
    u8 inCompletedTiming;
    u8 outStartTiming;
    u16 padding;
} spa_res_emitter_alphaanim_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_alphaanim_t) == 8);

typedef struct
{
    u8 frames[8];
    u32 frameCount : 8;
    u32 frameDuration : 8;
    u32 isRandom : 1;
    u32 loop : 1;
    u32 : 14;
} spa_res_emitter_texanim_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_texanim_t) == 0xC);

#define SPA_RES_EMITTER_CHILD_ROT_INHERIT_MODE_NONE		0
#define SPA_RES_EMITTER_CHILD_ROT_INHERIT_MODE_FREEZE	1
#define SPA_RES_EMITTER_CHILD_ROT_INHERIT_MODE_CONTINUE	2

typedef struct
{
    u16 applyEmitterField : 1;
    u16 useScaleAnim : 1;
    u16 hasAlphaFade : 1;
    u16 rotInheritMode : 2;
    u16 followEmitter : 1;
    u16 useChildColor : 1;
    u16 particleType : 2;
    u16 rotMtxMode : 2;
    u16 quadDirection : 1;
    u16 : 4;

    s16 initVelocityRandomness;
    fx16 targetScale;
    u16 lifeTime;
    u8 velocityInheritRatio;
    u8 scale;
    GXRgb color;
    u8 emissionVolume;
    u8 emissionTime;
    u8 emissionInterval;
    u8 textureId;

    u32 texRepeatShiftS : 2;
    u32 texRepeatShiftT : 2;
    u32 texFlipS : 1;
    u32 texFlipT : 1;
    u32 centerDirPolygon : 1;
    u32 : 25;
} spa_res_emitter_child_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_child_t) == 0x14);

typedef struct
{
    VecFx16 gravity;
    u16 padding;
} spa_res_emitter_field_gravity_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_gravity_t) == 8);

typedef struct
{
    VecFx16 strength;
    u16 interval;
} spa_res_emitter_field_random_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_random_t) == 8);

typedef struct
{
    VecFx32 magnetPos;
    fx16 magnetPower;
    u16 padding;
} spa_res_emitter_field_magnet_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_magnet_t) == 0x10);

#define SPA_RES_EMITTER_FIELD_SPIN_TYPE_X	0
#define SPA_RES_EMITTER_FIELD_SPIN_TYPE_Y	1
#define SPA_RES_EMITTER_FIELD_SPIN_TYPE_Z	2

typedef struct
{
    u16 rotation;
    u16 type;
} spa_res_emitter_field_spin_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_spin_t) == 4);

#define SPA_RES_EMITTER_FIELD_COLLISION_BEHAVIOR_DIE		0
#define SPA_RES_EMITTER_FIELD_COLLISION_BEHAVIOR_BOUNCE		1

typedef struct
{
    fx32 collisionPlaneY;
    fx16 bounceCoef;
    u16 behavior : 2;
    u16 : 14;
} spa_res_emitter_field_collision_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_collision_t) == 8);

typedef struct
{
    VecFx32 convergencePos;
    fx16 convergenceRatio;
    u16 padding;
} spa_res_emitter_field_convergence_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_emitter_field_convergence_t) == 0x10);

typedef struct
{
    u32 format : 4;
    u32 width : 4;
    u32 height : 4;
    u32 repeat : 2;
    u32 flip : 2;
    u32 pltt0Transparent : 1;
    u32 refTexData : 1;
    u32 refTexId : 8;
    u32 : 6;
} spa_res_texture_params_t;

typedef struct
{
    u32 signature;
    spa_res_texture_params_t texParams;
    u32 texSize;
    u32 plttOffset;
    u32 plttSize;
    u32 plttIdxOffset;
    u32 plttIdxSize;
    u32 blockSize;
} spa_res_texture_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_texture_t) == 0x20);

typedef struct
{
    u32 signature;
    u32 version;
    u16 emitterCount;
    u16 textureCount;
    u32 fieldC;
    u32 emitterBlockLength;
    u32 textureBlockLength;
    u32 textureBlockOffset;
    u32 field1C;
} spa_res_header_t;

SDK_COMPILER_ASSERT(sizeof(spa_res_header_t) == 0x20);
