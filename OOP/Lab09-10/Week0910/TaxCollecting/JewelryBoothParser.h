#pragma once
#pragma once
#include "IParsable.h"

class JewelryBoothParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};