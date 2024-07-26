#pragma once
#include "DxLib.h"
class Input;
class Player
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(Input input);
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// プレイヤーの当たり判定の座標を返す
	/// </summary>
	/// <returns>プレイヤーの現在の当たり判定の座標</returns>
	VECTOR GetColPos(){ return m_colPos; }

	/// <summary>
	/// プレイヤー描画位置を返す
	/// </summary>
	/// <returns>プレイヤーの描画座標</returns>
	VECTOR GetDrawPos() { return m_drawPos; }

	/// <summary>
	/// プレイヤーの向いている方向を取得する
	/// </summary>
	/// <returns></returns>
	VECTOR GetDir() { return m_dirVec; }

	/// <summary>
	/// 現在落下しているかどうか設定する
	/// </summary>
	/// <param name="fall">落下しているかどうか</param>
	void SetFall(bool fall) { m_isFall = fall; }
	
	void SetPos(VECTOR pos) { m_colPos = pos; }
private:
	//表示座標
	VECTOR m_drawPos;

	//今向いている方向
	VECTOR m_dirVec;

	//当たり判定の座標
	VECTOR m_colPos;

	//プレイヤーハンドル
	int m_handle;

	//上に向かう力
	float m_jumpPower;

	//落下しているかどうか
	bool m_isFall;
};

