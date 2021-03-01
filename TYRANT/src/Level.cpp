#include "..\include\Level.h"
#include "Level.h"
#include "Application.h"
#include "Entity.h"
namespace ty
{
	Level::Level(Application* App)
		:m_App(App)
	{

	}
	Level::~Level()
	{
	}
	void Level::BeginPlay()
	{
	}
	void Level::Tick(float DeltaTime)
	{
		for (int i = 0; i < m_Entities.size(); ++i)
		{
			m_Entities[i]->Tick(DeltaTime);
		}
		DestroyPendingKillEntities();
	}
	void Level::Draw()
	{
		//IN ORDER ORDER MATTERS
		DrawBackground();
		DrawEntities();
		DrawForeground();
	}
	void Level::DrawBackground()
	{
		GetApp()->GetWindow()->draw(m_BackGround);
	}
	void Level::DrawEntities()
	{
		for (int i = 0; i < m_Entities.size(); i++)
		{
			GetWindow()->draw(m_Entities[i]->GetVisual());
		}
	}
	void Level::DrawForeground()
	{
		//TODO : UI STUFF MAYBE
	}
	void Level::HandleInput()
	{
		for (int i = 0; i < m_Entities.size(); ++i)
		{
			m_Entities[i]->HandleInput();
		}
	}
	void Level::SetBackGround(const std::string& name)
	{
		m_BackGround.setTexture(LoadTexture(name));
	}
	const sf::Texture& Level::LoadTexture(const std::string& name)
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
	void Level::DestroyPendingKillEntities()
	{
		for (int i = 0; i < m_PendingDestoryEntities.size(); ++i) 
		{
			for (int j = 0; j < m_Entities.size(); ++j)
			{
				if (m_Entities[j].get() == m_PendingDestoryEntities[i])
				{
					m_Entities.erase(m_Entities.begin()+j);
				}
			}
		}
		m_PendingDestoryEntities.clear();
	}
}