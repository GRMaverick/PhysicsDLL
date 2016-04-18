#pragma once

#ifdef COMPONENTSDLL_EXPORTS
	#define COMPONENTSDLL_API __declspec(dllexport)
#else
	#define COMPONENTSDLL_API __declspec(dllimport)
#endif

#include "Commons.h"
#include "TransformComponent.h"

class RigidBody{
public:
	RigidBody(Transform* transform, float mass);
	~RigidBody();

	COMPONENTSDLL_API void Update(float deltaTime);
	COMPONENTSDLL_API void UpdateNetForce();
	COMPONENTSDLL_API void UpdateAcceleration();
	COMPONENTSDLL_API void UpdatePosition(float deltaTime);
	COMPONENTSDLL_API void UpdateRotation(float deltaTime);

	COMPONENTSDLL_API void ResetNetForce();

	COMPONENTSDLL_API void SetMass(float mass) { mInverseMass = 1 / mass; }
	COMPONENTSDLL_API void SetLift(XMFLOAT3 lift){ mLift = lift; }
	COMPONENTSDLL_API void SetDrag(XMFLOAT3 drag){ mDrag = drag; }
	COMPONENTSDLL_API void SetThrust(XMFLOAT3 thrust) { mThrust = thrust; }
	COMPONENTSDLL_API void SetWeight(XMFLOAT3 weight){ mWeight = weight; }
	COMPONENTSDLL_API void SetInertia(XMFLOAT3 inertia) { mInertia = inertia; }
	COMPONENTSDLL_API void SetTorque(XMFLOAT3 torque) { mTorque = torque; }
	COMPONENTSDLL_API void SetVelocity(XMFLOAT3 velocity) { mVelocity = velocity; }
	COMPONENTSDLL_API void SetTransform(Transform* transform) { mTransform = transform; }
	COMPONENTSDLL_API void SetAngularVelocity(XMFLOAT3 velocity) { mAngularVelocity = velocity; }
	COMPONENTSDLL_API void SetAcceleration(XMFLOAT3 acceleration) { mAcceleration = acceleration; }
	COMPONENTSDLL_API void SetAngularAcceleration(XMFLOAT3 acceleration) { mAngularAcceleration = acceleration; }

	COMPONENTSDLL_API float GetMass() const { return mInverseMass; }
	COMPONENTSDLL_API XMFLOAT3 GetInertia() const { return mInertia; }
	COMPONENTSDLL_API XMFLOAT3 GetTorque() const { return mTorque; }
	COMPONENTSDLL_API XMFLOAT3 GetVelocity() const{ return mVelocity; }
	COMPONENTSDLL_API Transform*   GetTransform() const { return mTransform; }
	COMPONENTSDLL_API XMFLOAT3 GetLift() const { return mLift; }
	COMPONENTSDLL_API XMFLOAT3 GetDrag() const { return mDrag; }
	COMPONENTSDLL_API XMFLOAT3 GetThrust() const { return mThrust; }
	COMPONENTSDLL_API XMFLOAT3 GetWeight() const { return mWeight; }
	COMPONENTSDLL_API XMFLOAT3 GetAcceleration() const { return mAcceleration; }
	COMPONENTSDLL_API XMFLOAT3 GetAngularVelocity() const { return mAngularVelocity; }
	COMPONENTSDLL_API XMFLOAT3 GetAngularAcceleration() const { return mAngularAcceleration; }

private:
	float					mInverseMass;
	float					mGravity;

	Transform*		mTransform;

	XMFLOAT3	mNetForce;

	XMFLOAT3	mLift;
	XMFLOAT3	mDrag;
	XMFLOAT3	mThrust;
	XMFLOAT3	mWeight;

	XMFLOAT3	mInertia;
	XMFLOAT3	mTorque;

	XMFLOAT3	mVelocity;
	XMFLOAT3	mAcceleration;
	XMFLOAT3	mAngularVelocity;
	XMFLOAT3	mAngularAcceleration;
};