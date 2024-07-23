// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controller/MainGamePC.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef PROJECTDS_MainGamePC_generated_h
#error "MainGamePC.generated.h already included, missing '#pragma once' in MainGamePC.h"
#endif
#define PROJECTDS_MainGamePC_generated_h

#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execLook);


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainGamePC(); \
	friend struct Z_Construct_UClass_AMainGamePC_Statics; \
public: \
	DECLARE_CLASS(AMainGamePC, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectDS"), NO_API) \
	DECLARE_SERIALIZER(AMainGamePC)


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainGamePC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMainGamePC(AMainGamePC&&); \
	AMainGamePC(const AMainGamePC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainGamePC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainGamePC); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainGamePC) \
	NO_API virtual ~AMainGamePC();


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_15_PROLOG
#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_INCLASS_NO_PURE_DECLS \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTDS_API UClass* StaticClass<class AMainGamePC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
