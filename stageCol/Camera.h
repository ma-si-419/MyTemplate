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
	void Update(Input input);
	/// <summary>
	/// カメラのターゲット座標を設定する
	/// </summary>
	/// <param name="pos">ターゲット座標</param>
	void SetTargetPos(VECTOR pos) { m_targetPos = pos; m_targetPos.y += 300; }

	/// <summary>
	/// カメラの座標を取得する
	/// </summary>
	/// <returns>カメラの座標</returns>
	VECTOR GetPos() { return m_pos; }

private:
	//表示座標
	VECTOR m_pos;

	//ターゲット座標
	VECTOR m_targetPos;
};

