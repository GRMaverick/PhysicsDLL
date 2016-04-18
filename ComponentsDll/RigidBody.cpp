#include "stdafx.h"
#include "RigidBody.h"
#include <stdexcept>


RigidBody::RigidBody(Transform* transform, float mass){
	mGravity = 9.81f;
	mInverseMass = 1 / mass;

	mTransform = transform;

	mNetForce = XMFLOAT3(0.0f, 0.0f, 0.0f);

	mWeight = XMFLOAT3(0.0f, mGravity * mInverseMass, 0.0f);
	mLift = mDrag = mThrust = XMFLOAT3(0.0f, 0.0f, 0.0f);

	mVelocity = mAcceleration = XMFLOAT3(0.0f, 0.0f, 0.0f);
	mAngularVelocity = mAcceleration = XMFLOAT3(0.0f, 0.0f, 0.0f);

	mTorque = mInertia = XMFLOAT3(0.0f, 0.0f, 0.0f);
}
RigidBody::~RigidBody(){

}

void RigidBody::Update(float deltaTime){
	this->UpdateNetForce();
	this->UpdateAcceleration();
	this->UpdatePosition(deltaTime);
	this->UpdateRotation(deltaTime);
	this->ResetNetForce();
}
void RigidBody::UpdateNetForce(){
	mNetForce.x = mLift.x + mDrag.x + mThrust.x + mWeight.x;
	mNetForce.y = mLift.y + mDrag.y + mThrust.y + mWeight.y;
	mNetForce.z = mLift.z + mDrag.z + mThrust.z + mWeight.z;
}
void RigidBody::UpdateAcceleration(){
	mAcceleration.x = mNetForce.x / mInverseMass;
	mAcceleration.y = mNetForce.y / mInverseMass;
	mAcceleration.z = mNetForce.z / mInverseMass;
}
void RigidBody::UpdatePosition(float deltaTime){
	XMFLOAT3 position = mTransform->GetPosition();

	position.x += mVelocity.x * deltaTime + 0.5 * mAcceleration.x * deltaTime * deltaTime;
	position.y += mVelocity.y * deltaTime + 0.5 * mAcceleration.y * deltaTime * deltaTime;
	position.z += mVelocity.z * deltaTime + 0.5 * mAcceleration.z * deltaTime * deltaTime;

	mTransform->SetPosition(position);

	mVelocity.x += mAcceleration.x * deltaTime;
	mVelocity.y += mAcceleration.y * deltaTime;
	mVelocity.z += mAcceleration.z * deltaTime;
}
void RigidBody::UpdateRotation(float deltaTime){
	XMFLOAT3 rotation = mTransform->GetRotation();

	rotation.x += mAngularVelocity.x * deltaTime + 0.5 * mAcceleration.x * deltaTime * deltaTime;
	rotation.y += mAngularVelocity.x * deltaTime + 0.5 * mAcceleration.y * deltaTime * deltaTime;
	rotation.z == mAngularVelocity.y * deltaTime + 0.5 * mAcceleration.z * deltaTime * deltaTime;

	mTransform->SetRotation(rotation);

	mAngularVelocity.x += mAcceleration.x * deltaTime;
	mAngularVelocity.y += mAcceleration.y * deltaTime;
	mAngularVelocity.z += mAcceleration.z * deltaTime;
}

void RigidBody::ResetNetForce(){
	mNetForce = XMFLOAT3(0.0f, 0.0f, 0.0f);
}