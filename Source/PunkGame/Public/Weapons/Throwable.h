// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "Throwable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UThrowable : public UInterface
{
	GENERATED_BODY()
};

class IThrowable
{
	GENERATED_BODY()

public:
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	virtual void Throw();
};