//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "DebugCamera.h"
#include "time.h"
#include "FollowCamera.h"
#include <Keyboard.h>

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>




// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{

public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_batch;
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;
	
	//デバックカメラ
	std::unique_ptr<DebugCamera> m_debugCamera;
	//エフェクトファクトリ
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	//地面モデル
	std::unique_ptr<DirectX::Model> m_modelGround;
	//地面モデル
	std::unique_ptr<DirectX::Model> m_modelGround200;
	//天球モデル
	std::unique_ptr<DirectX::Model> m_modelSkydome;
	//球モデル
	std::unique_ptr<DirectX::Model> m_modelSkyball;
	//ティーポットモデル
	std::unique_ptr<DirectX::Model> m_modeltepot;
	//headモデル
	std::unique_ptr<DirectX::Model> m_modelhead;
	//球ワールド行列
	DirectX::SimpleMath::Matrix m_worldBall1[10];
	DirectX::SimpleMath::Matrix m_worldBall2[10];
	/*地面ワールド行列*/
	DirectX::SimpleMath::Matrix m_worldGround;
	/*ティーポットワールド行列*/
	DirectX::SimpleMath::Matrix m_worldTepot[20];

	/*headワールド行列*/
	DirectX::SimpleMath::Matrix m_worldhead;
	/*回転させる変数*/
	float Rotation;

	float Distance;

	/*キーボード*/
	std::unique_ptr<DirectX::Keyboard> keyboard;

	/*自機の座標*/
	DirectX::SimpleMath::Vector3 tank_pos;

	/*自機の回転角*/
	float tank_angle;

	/*自機のワールド行列*/
	DirectX::SimpleMath::Matrix tank_world;

	/*カメラ*/
	std::unique_ptr<FollowCamera> m_Camera;


};