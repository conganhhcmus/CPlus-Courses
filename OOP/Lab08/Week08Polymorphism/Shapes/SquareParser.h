#pragma once
#include "IParsable.h"

class SquareParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};