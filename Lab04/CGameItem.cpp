/*
* CGameItem.cpp
* ---------------------------------------------
* Implementation for items
*
*/

#include "CGameItem.h"

// CSpell
CSpell::CSpell()
{
	_value = 5;
	_description = "Spell";
}

CSpell::CSpell(CSpell & right)
{
	_value = right._value;
	_description = right._description;
}

void CSpell::use()
{
	cout << "Cast spell" << endl;
}


// CPotion
CPotion::CPotion()
{
	_value = 2;
	_description = "Potion";
}

CPotion::CPotion(CPotion  & right)
{
	_value = right._value;
	_description = right._description;
}

void CPotion::use()
{
	cout << "Use potion" << endl;
}

// CSword
CSword::CSword()
{
	_value = 2;
	_description = "Sword";
}

CSword::CSword(CSword  & right)
{
	_value = right._value;
	_description = right._description;
}

void CSword::use()
{
	cout << "swing sword" << endl;
}

// CBow
CBow::CBow()
{
	_value = 2;
	_description = "Bow";
}

CBow::CBow(CBow  & right)
{
	_value = right._value;
	_description = right._description;
}

void CBow::use()
{
	cout << "string Bow" << endl;
}