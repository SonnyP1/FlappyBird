#include "Level.h"
#include "Application.h"
namespace ty
{
	Level::Level(Application* App)
		:m_App(App)
	{

	}
	void Level::BeginPlay()
	{
	}
	void Level::Tick(float DeltaTime)
	{
		//TODO: Tick entities
	}
	void Level::Draw()
	{
		DrawBackground();
		DrawEntities();
	}
	void Level::DrawBackground()
	{
		GetApp()->GetWindow()->draw(m_BackGround);
	}
	void Level::DrawEntities()
	{
		//TODO : draw entity
	}
	void Level::SetBackGround(const std::string& name)
	{
		m_BackGround.setTexture(LoadTexture(name));
	}
	sf::Texture& Level::LoadTexture(const std::string& name)
	{
		if (m_TextureAssets.find(name) == m_TextureAssets.end())
		{
			sf::Texture tx;
			if (tx.loadFromFile("Resources/Textures/" + name))
			{
				m_TextureAssets[name] = tx;
			}
		}

		return m_TextureAssets[name];
	}
}