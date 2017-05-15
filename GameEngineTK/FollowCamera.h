///_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//
// ���@�ɒǏ]����J�����N���X
//
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

#pragma once

#include "Camera.h"

class FollowCamera : public Camera
{
public:

	/*���@�ƃJ�����̋���*/
	static const float CAMERA_DISTANCE;

	/*�R���X�g���N�^*/
	FollowCamera(int width, int height);

	/*���t���[���X�V*/
	void Update() override;

	/*�Ǐ]�Ώۂ̍��W���Z�b�g*/
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	/*�Ǐ]�Ώۂ̍��W���Z�b�g*/
	void SetTargetAngle(float targetangle);

protected:

	/*�Ǐ]�Ώۂ̍��W*/
	DirectX::SimpleMath::Vector3 m_targetPos;

	/*�Ǐ]�Ώۂ̉�]�p*/
	float m_targetAngle;



};
