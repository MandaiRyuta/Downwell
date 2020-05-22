#pragma once

#define RELEASE

#ifdef DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

#include <string>
#include <memory>
#include <map>
#include <functional>
#include <list>
#include <assert.h>
#include <unordered_map>
#include <array>
#include <DxLib.h>

constexpr double ScreenWidth = 640.0;	//画面横幅
constexpr double ScreenHeight = 480.0;	//画面縦幅
constexpr signed short int True = 0x001;	//true
constexpr signed short int False = 0x000;	//false

/*初期化クラス*/
class Initialize
{
public:
	virtual void Init() = 0;
};

/*解放クラス*/
class Clear
{
public:
	virtual void Release() = 0;
};
#else
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <list>
#include <assert.h>
#include <unordered_map>
#include <array>
#include <DxLib.h>

constexpr double ScreenWidth = 640.0;	//画面横幅
constexpr double ScreenHeight = 480.0;	//画面縦幅
constexpr signed short int True = 0x001;	//true
constexpr signed short int False = 0x000;	//false

/*初期化クラス*/
class Initialize
{
public:
	virtual void Init() = 0;
};

/*解放クラス*/
class Clear
{
public:
	virtual void Release() = 0;
};
#endif