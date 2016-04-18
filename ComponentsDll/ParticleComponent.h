#pragma once

#ifdef COMPONENTSDLL_EXPORTS
#define COMPONENTSDLL_API __declspec(dllexport)
#else
#define COMPONENTSDLL_API __declspec(dllimport)
#endif

#include "Commons.h"
#include "TransformComponent.h"

class ParticleModel
{
public:
	COMPONENTSDLL_API ParticleModel(Transform* transform, float inverseMass);
	COMPONENTSDLL_API ~ParticleModel();

	COMPONENTSDLL_API void Update(float deltaTime);
	COMPONENTSDLL_API void UpdateNetForce();
	COMPONENTSDLL_API void UpdateAcceleration();
	COMPONENTSDLL_API void UpdatePosition(float deltaTime);

	COMPONENTSDLL_API void ResetNetForce();

	COMPONENTSDLL_API bool CollisionCheck(XMFLOAT3 position, float radius);

	COMPONENTSDLL_API inline void SetMass(float mass) { mInverseMass = 1 / mass; }
	COMPONENTSDLL_API inline void SetRadius(float radius) { mRadius = radius; }
	COMPONENTSDLL_API inline void SetLift(XMFLOAT3 lift) { mLift = lift; }
	COMPONENTSDLL_API inline void SetDrag(XMFLOAT3 drag) { mDrag = drag; }
	COMPONENTSDLL_API inline void SetThrust(XMFLOAT3 thrust) { mThrust = thrust; }
	COMPONENTSDLL_API inline void SetWeight(XMFLOAT3 weight) { mWeight = weight; }
	COMPONENTSDLL_API inline void SetVelocity(XMFLOAT3 velocity) { mVelocity = velocity; }
	COMPONENTSDLL_API inline void SetNetForce(XMFLOAT3 nForce) { mNetForce = nForce; }
	COMPONENTSDLL_API inline void SetAcceleration(XMFLOAT3 acceleration) { mAcceleration = acceleration; }

	COMPONENTSDLL_API inline float GetMass() const { return mInverseMass; }
	COMPONENTSDLL_API inline float GetRadius() const { return mRadius; }
	COMPONENTSDLL_API inline Transform* GetTransform() const { return mTransform; }
	COMPONENTSDLL_API inline XMFLOAT3 GetLift() const { return mLift; }
	COMPONENTSDLL_API inline XMFLOAT3 GetDrag() const { return mDrag; }
	COMPONENTSDLL_API inline XMFLOAT3 GetThrust() const { return mThrust;	}
	COMPONENTSDLL_API inline XMFLOAT3 GetWeight() const { return mWeight; }
	COMPONENTSDLL_API inline XMFLOAT3 GetVelocity() const { return mVelocity; }
	COMPONENTSDLL_API inline XMFLOAT3 GetNetForce() const { return mNetForce; }
	COMPONENTSDLL_API inline XMFLOAT3 GetAcceleration() const { return mAcceleration; }

private:
	float									mInverseMass;
	float									mRadius;
	float									mDamping;
	float									mGravity;

	XMFLOAT3						mNetForce;
	XMFLOAT3						mWeight;
	XMFLOAT3						mLift;
	XMFLOAT3						mDrag;
	XMFLOAT3						mThrust;

	Transform*						mTransform;

	XMFLOAT3						mVelocity;
	XMFLOAT3						mAcceleration;
};