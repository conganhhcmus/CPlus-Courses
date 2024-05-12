#pragma once
#include "IParsable.h"

class CircleParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};