#include "PopUp.h"



PopUp::PopUp()
{
	mTexture.loadFromFile("Assets/sprites/PopUpTest.png");
	mSprite.setTexture(mTexture);


	mFont.loadFromFile("Assets/Text/arial.ttf");
	mText.setFont(mFont);
	mText.setScale(0.7f, 0.7f);
	mText.setString("Test String");
}

PopUp::~PopUp()
{
}

sf::Vector2f PopUp::GetPosition() const
{
	return mPosition;
}

sf::Vector2u PopUp::GetTextureSize() const
{
	return mTexture.getSize();
}

bool PopUp::IsTextOpen()
{
	return mIsTextOpen;
}

bool PopUp::IsCharacterMovementLocked()
{
	return mStopPlayerMovement;
}

void PopUp::SetPosition(sf::Vector2f _pos)
{
	mPosition = _pos;
}

void PopUp::OpenText(std::string _filepath, bool _lockPlayerMovement)
{
	mDialogueLines.clear();
	std::ifstream fstream;
	std::string temp;
	char c;
	bool done = false;

	fstream.open(_filepath);

	if (fstream.is_open())
	{
		while (!fstream.eof())
		{
			while (fstream.get(c) && c != '^')
			{
				temp.push_back(c);
			}
				mDialogueLines.push_back(temp);
				temp = "";
				fstream.get(c);
		}
		fstream.close();
	}
	else
	{
		std::cout << "failed to open file" << std::endl;
	}


	mStopPlayerMovement = _lockPlayerMovement;
	mIsTextOpen = true;

	mCurrentLineNumber = 0;
	mText.setString(mDialogueLines.at(mCurrentLineNumber));
}

void PopUp::CycleText()
{
	if (mIsTextOpen)
	{
		if ((mCurrentLineNumber + 1) < mDialogueLines.size())
		{
			mCurrentLineNumber++;
			mText.setString(mDialogueLines[mCurrentLineNumber]);
		}
		else
		{
			mIsTextOpen = false;
			mStopPlayerMovement = false;
		}
	}
}

void PopUp::Draw(sf::RenderWindow & window)
{
	if (mIsTextOpen)
	{
		window.draw(mSprite);
		window.draw(mText);
	}
}

void PopUp::Update(float dt)
{
	if (mIsTextOpen)
	{
		mSprite.setPosition(mPosition);
		mText.setPosition(sf::Vector2f(mPosition.x + 20, mPosition.y + 15));
	}
}
