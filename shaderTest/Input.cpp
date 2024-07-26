#include "Input.h"


Input::Input()
{
	//�{�^���̐ݒ�
	m_inputActionMap["OK"] = { {InputType::kKeyboard,KEY_INPUT_RETURN},{InputType::kPad,PAD_INPUT_A} };
	m_inputActionMap["pause"] = { {InputType::kKeyboard,KEY_INPUT_P}, {InputType::kPad,PAD_INPUT_START} };
	m_inputActionMap["cancel"] = { {InputType::kKeyboard,KEY_INPUT_ESCAPE}, {InputType::kPad,PAD_INPUT_B} };
	m_inputActionMap["up"] = { {InputType::kKeyboard,KEY_INPUT_UP}, {InputType::kPad,PAD_INPUT_UP} };
	m_inputActionMap["down"] = { {InputType::kKeyboard,KEY_INPUT_DOWN}, {InputType::kPad,PAD_INPUT_DOWN} };
	m_inputActionMap["left"] = { {InputType::kKeyboard,KEY_INPUT_LEFT}, {InputType::kPad,PAD_INPUT_LEFT} };
	m_inputActionMap["right"] = { {InputType::kKeyboard,KEY_INPUT_RIGHT}, {InputType::kPad,PAD_INPUT_RIGHT} };
	m_inputActionMap["jump"] = { {InputType::kKeyboard,KEY_INPUT_SPACE}, {InputType::kPad,PAD_INPUT_A} };
	m_inputActionMap["LB"] = { {InputType::kKeyboard,KEY_INPUT_Q}, {InputType::kPad,PAD_INPUT_LL} };
	m_inputActionMap["RB"] = { {InputType::kKeyboard,KEY_INPUT_E}, {InputType::kPad,PAD_INPUT_RR} };
	
}
void Input::Update()
{
	//�O�̃t���[���̓��͏���ۑ�����
	m_lastInput = m_currentInput;

	//���ׂĂ̓��͂��擾����
	char keyState[256] = {};
	int padState = {};
	int mouseState = {};
	GetHitKeyStateAll(keyState);
	padState = GetJoypadInputState(DX_INPUT_PAD1);
	mouseState = GetMouseInput();


	//�A�N�V�������Ɋ��蓖�Ă��Ă��邷�ׂẴL�[�̓��͂��`�F�b�N����
	for (const auto& keyInfo : m_inputActionMap)
	{
		bool isPress = false;
		for (const auto& inputInfo : keyInfo.second)
		{
			//�L�[�{�[�h�̃`�F�b�N
			if (inputInfo.type == InputType::kKeyboard && keyState[inputInfo.buttonID])
			{
				isPress = true;
			}
			//�p�b�h�̃`�F�b�N
			if (inputInfo.type == InputType::kPad && padState & inputInfo.buttonID)
			{
				isPress = true;
			}
			//�}�E�X�̃`�F�b�N
			if (inputInfo.type == InputType::kMouse && mouseState & inputInfo.buttonID)
			{
				isPress = true;
			}

			//�{�^����������Ă����烋�[�v�𔲂���
			if (isPress)
			{
				break;
			}
		}
		//���݂̃t���[���ŉ�����Ă������ǂ�����Ԃ�
		m_currentInput[keyInfo.first] = isPress;
	}

	//�X�e�B�b�N�̓��͂�����������
	m_stickInfo.leftStickX = 0;
	m_stickInfo.leftStickY = 0;
	m_stickInfo.rightStickX = 0;
	m_stickInfo.rightStickY = 0;

	//�X�e�B�b�N�̓��͂��擾����
	GetJoypadAnalogInput(&m_stickInfo.leftStickX, &m_stickInfo.leftStickY, DX_INPUT_PAD1);
	GetJoypadAnalogInputRight(&m_stickInfo.rightStickX, &m_stickInfo.rightStickY, DX_INPUT_PAD1);
}

bool Input::IsPress(const std::string& action) const
{
	auto keyInfo = m_currentInput.find(action);

	//�{�^��������`����Ă��Ȃ�������false��Ԃ�
	if (keyInfo == m_currentInput.end())
	{
		return false;
	}
	else
	{
		//����������bool�̒l��Ԃ�
		return keyInfo->second;
	}
}

bool Input::IsTrigger(const std::string& action) const
{
	//�܂�������Ă��邩�ǂ�������
	if (IsPress(action))
	{
		//�O�̃t���[�����Q��
		auto last = m_lastInput.find(action);
		//����`�̃{�^������������false��Ԃ�
		if (last == m_lastInput.end())
		{
			return true;
		}
		//�O�̃t���[���ł�������Ă�����
		else
		{
			return !last->second;
		}
	}
	else
	{
		return false;
	}
}

