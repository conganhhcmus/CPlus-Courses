#pragma once
#include "IParsable.h"

class ClothesBoothParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};