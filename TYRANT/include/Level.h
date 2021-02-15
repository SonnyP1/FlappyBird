#pragma once
#include <TyrantCore.h>
namespace ty
{
	class TYRANT_API Level
	{
	public:
		Level(class Application* App);
		class Application* GetApp() { return m_App; };

		//game loop
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		virtual void Draw();
		virtual void DrawBackground();
		virtual void DrawEntities();

		void SetBackGround(const std::string& name);
		sf::Sprite& GetBackGround() { return m_BackGround; };

		//asset managing
		sf::Texture& LoadTexture(const std::string& name);
	private:
		class Application* m_App;
		sf::Sprite m_BackGround;
		std::map<std::string, sf::Texture> m_TextureAssets;
	};
}

