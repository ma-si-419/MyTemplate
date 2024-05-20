#include "Triangle.h"
#include <math.h>
Triangle::Triangle()
{
	m_pos1 = VGet(-100, 0, -200);
	m_pos2 = VGet(200, 0, 0);
	m_pos3 = VGet(-200, 0, 100);

}

void Triangle::Update(VECTOR targetPos)
{
	m_targetPos = targetPos;
}

void Triangle::Draw()
{
	DrawTriangle3D(m_pos1, m_pos2, m_pos3, GetColor(255, 0, 0), true);
	DrawSphere3D(m_pos1, 5, 10, GetColor(255, 0, 0), GetColor(255, 255, 255), true);
	DrawSphere3D(m_pos2, 5, 10, GetColor(0, 255, 0), GetColor(255, 255, 255), true);
	DrawSphere3D(m_pos3, 5, 10, GetColor(0, 0, 255), GetColor(255, 255, 255), true);
}

VECTOR Triangle::SetTargetPos(VECTOR pos)
{
	VECTOR ansPos = pos;

	//�_1����2�Ɍ������x�N�g��
	VECTOR firstToSecondVec = VSub(m_pos2, m_pos1);
	//�_2����Ɍ������x�N�g��
	VECTOR secondToThirdVec = VSub(m_pos3, m_pos2);;
	//�_3����1�Ɍ������x�N�g��
	VECTOR thirdToFirstVec = VSub(m_pos1, m_pos3);;

	/*�x�N�g���̐��K��*/
	firstToSecondVec = VNorm(firstToSecondVec);
	secondToThirdVec = VNorm(secondToThirdVec);
	thirdToFirstVec = VNorm(thirdToFirstVec);

	//�_1����^�[�Q�b�g�Ɍ������x�N�g��
	VECTOR firstToTarget = VSub(ansPos, m_pos1);
	//�_2����^�[�Q�b�g�Ɍ������x�N�g��
	VECTOR secondToTarget = VSub(ansPos, m_pos2);
	//�_3����^�[�Q�b�g�Ɍ������x�N�g��
	VECTOR thirdToTarget = VSub(ansPos, m_pos3);

	//�O�ς����߂�
	float cross1 = VCross(firstToSecondVec, firstToTarget).y;
	float cross2 = VCross(secondToThirdVec, secondToTarget).y;
	float cross3 = VCross(thirdToFirstVec, thirdToTarget).y;

	bool isHit = false;
	//�������Ă��邩�ǂ�������
	if (cross1 >= 0.0f)
	{
		if (cross2 >= 0.0f && cross3 >= 0.0f)
		{
			isHit = true;
		}
	}
	else
	{
		if (cross2 < 0.0f && cross3 < 0.0f)
		{
			isHit = true;
		}
	}
	//�������Ă�������W�𒲐�����
	if (isHit)
	{
		/*�ǂ̕ӂɈ�ԋ߂����擾����*/

		//�_1����_2�܂ł̕ӂ���ԋ߂��ꍇ
		if (fabsf(cross1) <= fabsf(cross2) && fabsf(cross1) <= fabsf(cross3))
		{
			float fDot = VDot(firstToSecondVec, firstToTarget);
			ansPos = VGet(firstToSecondVec.x * fDot + m_pos1.x, 0, firstToSecondVec.z * fDot + m_pos1.z);
		}
		//�_2����_3�̕ӂ���ԋ߂��ꍇ
		else if (fabsf(cross2) <= fabsf(cross3))
		{
			float fDot = VDot(secondToThirdVec, secondToTarget);
			ansPos = VGet(secondToThirdVec.x * fDot + m_pos2.x, 0, secondToThirdVec.z * fDot + m_pos2.z);
		}
		//�_3����_1�̕ӂ���ԋ߂��ꍇ
		else
		{
			float fDot = VDot(thirdToFirstVec, thirdToTarget);
			ansPos = VGet(thirdToFirstVec.x * fDot + m_pos3.x, 0, thirdToFirstVec.z * fDot + m_pos3.z);
		}
		//ansPos = m_targetPos;
		DrawString(500, 0, "������", GetColor(255, 255, 255));
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "targetPos: x%.2f,z%.2f", ansPos.x, ansPos.z);

	DrawFormatString(0, 25, GetColor(255, 255, 255), "nextPos: x%.2f,z%.2f", pos.x, pos.z);

	DrawFormatString(0, 50, GetColor(255, 255, 255), "�O�ό���: 1=%.2f,2=%.2f,3=%.2f", cross1, cross2, cross3);

	return ansPos;
}

