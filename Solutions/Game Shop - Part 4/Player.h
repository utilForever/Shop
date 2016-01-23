#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();
	Player(int gold);

	int GetGold() const;
	void SetGold(int gold);
private:
	int m_gold;
};

#endif