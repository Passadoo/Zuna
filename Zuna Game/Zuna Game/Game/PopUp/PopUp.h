#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "../Utilities/Defines.h"
class PopUp
{
public:
	PopUp();
	~PopUp();

	sf::Vector2f GetPosition()const;
	sf::Vector2u GetTextureSize()const;
	bool IsTextOpen();
	bool IsCharacterMovementLocked();

	void SetPosition(sf::Vector2f _pos);

	void OpenText(std::string _filepath, bool _lockPlayerMovement);
	void CycleText();

	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float dt);

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;
	sf::Font mFont;
	sf::Text mText;

	int mCurrentLineNumber = 0;
	std::vector<std::string> mDialogueLines;

	bool mIsTextOpen = false;
	bool mStopPlayerMovement = false;


	sf::Vector2f mPosition;

};