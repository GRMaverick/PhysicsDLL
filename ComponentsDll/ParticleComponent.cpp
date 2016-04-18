#include "stdafx.h"
#include "ParticleComponent.h"
#include <stdexcept>


ParticleModel::ParticleModel(Transform* transform, float inverseMass){
	mGravity = 9.81;
	mTransform = transform;
	mInverseMass = inverseMass;
	mDamping = 0.5f;
	mWeight = XMFLOAT3(0.0f, mInverseMass * -mGravity, 0.0f);
	mVelocity = mAcceleration = mNetForce = mLift = mThrust = mDrag = XMFLOAT3(0.0f, 0.0f, 0.0f);
}
ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(float deltaTime)
{
	this->UpdateNetForce();
	this->UpdateAcceleration();
	this->UpdatePosition(deltaTime);

	powf(mDamping, deltaTime);

	this->ResetNetForce();
}

void ParticleModel::UpdateNetForce(){
	mNetForce.x = mWeight.x + mLift.x + mDrag.x + mThrust.x;
	mNetForce.y = mWeight.y + mLift.y + mDrag.y + mThrust.y;
	mNetForce.z = mWeight.z + mLift.z + mDrag.z + mThrust.z;
}
void ParticleModel::UpdateAcceleration()
{
	mAcceleration.x = mNetForce.x / mInverseMass;
	mAcceleration.y = mNetForce.y / mInverseMass;
	mAcceleration.z = mNetForce.z / mInverseMass;
}
void ParticleModel::UpdatePosition(float deltaTime)
{
	XMFLOAT3 position = mTransform->GetPosition();

	position.x += mVelocity.x * deltaTime + 0.5 * mAcceleration.x * deltaTime * deltaTime;
	position.y += mVelocity.y * deltaTime + 0.5 * mAcceleration.y * deltaTime * deltaTime;
	position.z += mVelocity.z * deltaTime + 0.5 * mAcceleration.z * deltaTime * deltaTime;

	mTransform->SetPosition(position);

	mVelocity.x += mAcceleration.x * deltaTime;
	mVelocity.y += mAcceleration.y * deltaTime;
	mVelocity.z += mAcceleration.z * deltaTime;
}

void ParticleModel::ResetNetForce(){
	mNetForce = XMFLOAT3(0.0f, 0.0f, 0.0f);
}

bool ParticleModel::CollisionCheck(XMFLOAT3 position, float radius){
	XMFLOAT3 vector = XMFLOAT3(position.x - mTransform->GetPosition().x, position.y - mTransform->GetPosition().y, position.z - mTransform->GetPosition().z);
	float distance = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));

	if (distance > (mRadius + radius))
		return false;

	return true;
}

