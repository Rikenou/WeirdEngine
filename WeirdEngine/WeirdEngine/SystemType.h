#pragma once
#include <string>

struct SystemType{

	std::string Type;

	bool operator == (const SystemType other) {

		if (Type == other.Type)
			return true;

		else
			return false;

	}

	bool operator != (const SystemType other) {

		if (Type != other.Type)
			return true;

		else
			return false;

	}

};

