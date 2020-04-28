#pragma once

#define DEBUG

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

constexpr double ScreenWidth = 640.0;
constexpr double ScreenHeight = 480.0;
constexpr signed short int True = 0x001;
constexpr signed short int False = 0x000;

template<typename T, size_t size>
using Array = std::array<T, size>;

using String = std::string;

template<class T>
using UniquePtr = std::unique_ptr<T>;

template<class T>
using SharedPtr = std::shared_ptr<T>;

template<class Key, class Value>
using Map = std::map<Key, Value>;

template<class T>
using Function = std::function<T>;

template<class T>
using List = std::list<T>;

template<typename Key, class Value>
using Unordered_Map = std::unordered_map<Key,Value>;

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