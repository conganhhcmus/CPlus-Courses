#pragma once
#include "IParsable.h"

class IdeaProjectParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};