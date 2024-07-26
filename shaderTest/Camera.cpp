#include "Camera.h"
#include "Input.h"
namespace
{
	const VECTOR kCameraInitPos = VGet(0, 50, -100);

	const VECTOR kCameraPos = VGet(0,30,-50);
}
Camera::Camera() :
	m_pos(kCameraInitPos)
{
	SetCameraNearFar(1.0f,500.0f);
	SetCameraPositionAndTarget_UpVecY(kCameraPos, VGet(0, 0, 0));
}

Camera::~Camera()
{
}

void Camera::Update(Input input, VECTOR target)
{
	m_pos = VAdd(target, kCameraPos);

	SetCameraPositionAndTarget_UpVecY(m_pos, target);
}
