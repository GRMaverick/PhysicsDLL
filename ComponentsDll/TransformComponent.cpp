#include "stdafx.h"
#include "TransformComponent.h"
#include <stdexcept>

Transform::Transform()
{
	mParent = nullptr;
	mPreviousPosition = XMFLOAT3();
	mPosition = XMFLOAT3();
	mRotation = XMFLOAT3();
	mScale = XMFLOAT3(1.0f, 1.0f, 1.0f);
}
Transform::~Transform()
{
}

void Transform::Update(float t)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(mScale.x, mScale.y, mScale.z);
	XMMATRIX rotation = XMMatrixRotationX(mRotation.x) * XMMatrixRotationY(mRotation.y) * XMMatrixRotationZ(mRotation.z);
	XMMATRIX translation = XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z);

	XMStoreFloat4x4(&mWorld, scale * rotation * translation);

	if (mParent != nullptr)
	{
		XMStoreFloat4x4(&mWorld, this->GetWorldMatrix() * mParent->GetWorldMatrix());
	}
}

void Transform::SetPosition(XMFLOAT3 position){
	mPreviousPosition = mPosition;
	mPosition = position;
}
void Transform::SetPosition(float x, float y, float z){
	mPreviousPosition.x = mPosition.x; mPreviousPosition.y = mPosition.y; mPreviousPosition.z = mPosition.z;
	mPosition.x = x; mPosition.y = y; mPosition.z = z;
}