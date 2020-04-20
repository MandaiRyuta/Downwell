#pragma once

#define DEBUG

#ifdef DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#ifdef DEBUG
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <list>
#include <assert.h>
#include <unordered_map>
#include <DxLib.h>

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
#endif