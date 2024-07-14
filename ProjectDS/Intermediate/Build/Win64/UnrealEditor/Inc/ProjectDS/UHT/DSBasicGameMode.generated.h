// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameMode/DSBasicGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTDS_DSBasicGameMode_generated_h
#error "DSBasicGameMode.generated.h already included, missing '#pragma once' in DSBasicGameMode.h"
#endif
#define PROJECTDS_DSBasicGameMode_generated_h

#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADSBasicGameMode(); \
	friend struct Z_Construct_UClass_ADSBasicGameMode_Statics; \
public: \
	DECLARE_CLASS(ADSBasicGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectDS"), NO_API) \
	DECLARE_SERIALIZER(ADSBasicGameMode)


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADSBasicGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADSBasicGameMode(ADSBasicGameMode&&); \
	ADSBasicGameMode(const ADSBasicGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADSBasicGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADSBasicGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADSBasicGameMode) \
	NO_API virtual ~ADSBasicGameMode();


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_12_PROLOG
#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTDS_API UClass* StaticClass<class ADSBasicGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
