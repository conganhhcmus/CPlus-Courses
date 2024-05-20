#pragma once
#include "IParsable.h"

class MVPProjectParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};