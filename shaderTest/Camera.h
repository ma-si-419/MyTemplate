#pragma once
#include "DxLib.h"
class Input;
class Camera
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Camera();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Camera();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(Input input,VECTOR target);
	
	VECTOR GetPos() { return m_pos; }

private:
	//表示座標
	VECTOR m_pos;
};

