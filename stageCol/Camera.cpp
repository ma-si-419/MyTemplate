#include "Camera.h"
#include "Input.h"
namespace
{
	const VECTOR kCameraInitPos = VGet(0, -500, -500);

	const VECTOR kCameraPos = VGet(0,0,-300);
}
Camera::Camera() :
	m_pos(kCameraInitPos),
	m_targetPos(VGet(0, 0, 0))
{
	SetCameraPositionAndTarget_UpVecY(m_pos, m_targetPos);
}

Camera::~Camera()
{
}

void Camera::Update(Input input)
{



	m_pos = VAdd(m_targetPos,kCameraPos);



	SetCameraPositionAndTarget_UpVecY(m_pos, m_targetPos);
}
