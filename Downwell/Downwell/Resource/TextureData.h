#pragma once

#include "../Constant.h"

namespace TextureDataBase
{
	class TextureData
	{
	private:
		TextureData() {};
		~TextureData() {};
	public:
		static TextureData& GetInstance()
		{
			static TextureData Inst;
			return Inst;
		}

		void Init();
		void Loading(int& scenetype);
		
		const int& GetTextureData(String name);
	private:
		std::unordered_map<String, int> Texture_;
	};
}