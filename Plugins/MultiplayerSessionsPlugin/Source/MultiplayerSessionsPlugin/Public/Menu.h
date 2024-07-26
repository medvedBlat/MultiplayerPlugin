// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONSPLUGIN_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnection = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")));

	//
	//Custom delegates for callbacks
	//
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult> &SessionsResult, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Resuslt);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	

protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;
	
private:

	UPROPERTY(meta =(BindWidget))
	class UButton *HostButton;
	
	UPROPERTY(meta =(BindWidget))
	UButton *JoinButton;

	UFUNCTION()
	void JoinButtonClicked();

	UFUNCTION()
	void HostButtonClicked();

	void MenuTearDown();

	class UMultiplayerSessionsSubsystem *MultiplayerSessionsSubsystem;

	int32 NumOfPublicConnections{4};
	FString MatchType{TEXT("FreeForAll")};
	
};
