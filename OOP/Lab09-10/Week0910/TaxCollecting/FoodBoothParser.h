#pragma once
#include "IParsable.h"

class FoodBoothParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};