#pragma once
#include "IParsable.h"

class RectangleParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};